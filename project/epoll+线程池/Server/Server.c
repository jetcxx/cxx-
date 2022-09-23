#include "server.h"
extern Online_user_list *head;
extern sqlite3* datebase;
extern  struct pthreadpool *pool ;
extern struct pthreadpool *InitPthreadPool(int, int);
extern void ThreadAddJob(struct pthreadpool *pool, void *(*func)(void *arg), void *arg);
extern void *work(void *arg);
extern void Create_Sqlite();
int socket_init()
{

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket error");
        return -1;
    }
    //设置套接字端口属性为端口释放后可以重复使用
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    //将套接字进行IP与端口的绑定
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr)); //清空内存
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);              //端口和ip要改成大端模式
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ALL表示任意ip
    int ret = bind(sockfd, (struct sockaddr *)&(addr), sizeof(addr));
    if (ret == -1)
    {
        perror("bind error");
        printf("绑定套接字失败.\n");
        return -1;
    }
    //监听
    ret = listen(sockfd, 3);
    if (ret == -1)
    {
        perror("listen error");
        printf("监听套接字失败.\n");
        return -1;
    }
    printf("客户机已经开启,等待用户连接中.....\n");
    return sockfd;
}

// epoll操作
int mypoll(int sockfd)
{
    int N = sizeof(Msg);
    struct sockaddr_in clientaddr;
    socklen_t addrlen = sizeof(clientaddr);
    //第一步：创建epoll对象
    int epfd = epoll_create(2000);
    if (-1 == epfd)
    {
        ERRLOG("epoll");
    }
    struct epoll_event ev, events[2000] = {0};
    ev.events = EPOLLIN; //监听sockfd可读
    ev.data.fd = sockfd;
    int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);
    if (-1 == ret)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }
    int i;
    int acceptfd = 0;
    while (1)
    {
        Msg msg;
        int num = epoll_wait(epfd, events, 2000, -1);
        if (-1 == num)
        {
            printf("epoll_wait() failed\n");
            return -1;
        }
        for (i = 0; i < num; i++)
        {
            if (events[i].data.fd == sockfd) //表示有客户端发起链接
            {
                if ((acceptfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen)) == -1)
                {
                    ERRLOG("accept error");
                }
                //为新的文件描述符注册事件
                printf("accept fd  %d\n", acceptfd);
                ev.events = EPOLLIN; //监听sockfd可读
                ev.data.fd = acceptfd;
                int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, acceptfd, &ev);
                if (-1 == ret)
                {
                    ERRLOG("epoll_ctl");
                }
                printf("客户端%s:%d 连接了\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
            }
            else //有客户端发消息
            {
                Myarg arg;
                memset(&arg, 0, sizeof(Myarg));
                if (events[i].events & EPOLLIN) //如果事件是可读的
                {
                    memset(&msg, 0, sizeof(msg));
                    ret = recv(events[i].data.fd, &msg, N, 0);
                    if (ret == -1)
                    {
                        ERRLOG("recv");
                    }
                    else if (0 == ret)
                    {
                        ev.events = EPOLLIN; //监听sockfd可读
                        ev.data.fd = events[i].data.fd;
                        int ret = epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, &ev); //客户端退出，注销事件
                        if (-1 == ret)
                        {
                            ERRLOG("epoll_ctl");
                        }
                        close(events[i].data.fd);
                    }
                    //信息拷贝
                   arg.msg.cmd=msg.cmd;
                   arg.fd=acceptfd;
                   strcpy(arg.msg.sourceName, msg.sourceName);
                   strcpy(arg.msg.destinationName, msg.destinationName);
                   strcpy(arg.msg.buffer, msg.buffer);
                   ThreadAddJob(pool, work, (void *)&arg);
                }
            }
        }
    }
}

void Creat_head()
{
    head = (Online_user_list *)malloc(sizeof(Online_user_list));
    if (head == NULL)
    {
        printf("creat_head error\n");
        return;
    }
    head->next = NULL;
}

int add_user(Msg mymsg, int client_socket)
{
    Online_user_list *newuser = (Online_user_list *)malloc(sizeof(Online_user_list));
    if (newuser == NULL)
    {
        printf("Error allocating memory for user list\n");
        return -1;
    }
    newuser->next = head->next;
    newuser->fd = client_socket;
    head->next = newuser;
    strcpy(newuser->name, mymsg.sourceName);
    return 0;
}

int find_user_list(char *name) //没找到就返回0
{
    Online_user_list *tmp = head->next;
    while (tmp != NULL)
    {
        printf("%s\n", tmp->name);
        if (strcmp(tmp->name, name) == 0)
        {
            return -1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int find_user(char *name)
{
    Online_user_list *tmp = head->next;
    while (tmp != NULL)
    {
        if (strcmp(tmp->name, name) == 0)
        {
            return tmp->fd;
        }
        tmp = tmp->next;
    }
    return 0;
}
