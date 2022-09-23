#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/epoll.h>

int sockfd;
//消息结构体
struct MSG_DATA
{
    char type; //消息类型.  0表示有聊天的消息数据  1表示好友上线  2表示好友下线
    char name[50]; //好友名称
    int number;   //在线人数的数量
    unsigned char buff[100];  //发送的聊天数据消息
};

//存放当前服务器连接的客户端套接字
struct CLIENT_FD
{
    int fd;
    char name[50]; //名称
    struct CLIENT_FD *next;
};

//定义链表头
struct CLIENT_FD *list_head=NULL;
struct CLIENT_FD *List_CreateHead(struct CLIENT_FD *list_head);
void List_AddNode(struct CLIENT_FD *list_head,int fd);
void List_DelNode(struct CLIENT_FD *list_head,int fd);
int List_GetNodeCnt(struct CLIENT_FD *list_head);
void Server_SendMsgData(struct CLIENT_FD *list_head,struct MSG_DATA *msg_data,int client_fd);
void List_SaveName(struct CLIENT_FD *list_head,struct MSG_DATA *msg_data,int client_fd);
void List_GetName(struct CLIENT_FD *list_head,struct MSG_DATA *msg_data,int client_fd);

#define MAX_EPOLL_FD 100
struct epoll_event events[MAX_EPOLL_FD];
struct epoll_event event;
int epfd;
int nfd;
struct MSG_DATA msg_data;

/*信号工作函数*/
void signal_work_func(int sig)
{
    close(sockfd);
    exit(0); //结束进程
}

int main(int argc,char **argv)
{   
    if(argc!=2)
    {
        printf("./app <端口号>\n");
        return 0;
    }
    signal(SIGPIPE,SIG_IGN); //忽略 SIGPIPE 信号--防止服务器异常退出
    signal(SIGINT,signal_work_func);

    //创建链表头
    list_head=List_CreateHead(list_head);

    /*1. 创建socket套接字*/
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    //设置端口号的复用功能
    int on = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    /*2. 绑定端口号与IP地址*/
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(atoi(argv[1])); // 端口号0~65535
    addr.sin_addr.s_addr=INADDR_ANY;    //inet_addr("0.0.0.0"); //IP地址
    if(bind(sockfd,(const struct sockaddr *)&addr,sizeof(struct sockaddr))!=0)
    {
        printf("服务器:端口号绑定失败.\n");
    }
    /*3. 设置监听的数量*/
    listen(sockfd,20);
    /*4. 等待客户端连接*/
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t addrlen;
    int i;
    int cnt;

    /*5. 创建epoll相关的接口*/
    epfd=epoll_create(MAX_EPOLL_FD);
    event.events=EPOLLIN;  //监听的事件
    event.data.fd=sockfd; //监听的套接字
    epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&event);
    while(1)
    {
        //等待事件发生
        nfd=epoll_wait(epfd,events,MAX_EPOLL_FD,-1);
        for(i=0;i<nfd;i++)
        { 
            if(events[i].data.fd==sockfd)  //表示有新的客户端连接上服务器
            {
                client_fd=accept(sockfd,(struct sockaddr *)&client_addr,&addrlen);
                printf("连接的客户端IP地址:%s\n",inet_ntoa(client_addr.sin_addr));
                printf("连接的客户端端口号:%d\n",ntohs(client_addr.sin_port));
                //保存已经连接上来的客户端
                List_AddNode(list_head,client_fd);
                //将新连接的客户端套接字添加到epoll函数监听队列里
                event.data.fd=client_fd; //监听的套接字
                epoll_ctl(epfd,EPOLL_CTL_ADD,client_fd,&event);
            }
            else  //表示客户端给服务器发送了消息-----实现消息的转发
            {
                 //读取客户端发送的消息
                cnt=read(events[i].data.fd,&msg_data,sizeof(struct MSG_DATA));
                if(cnt<=0)  //表示当前客户端断开了连接
                {
                    //获取名称
                    List_GetName(list_head,&msg_data,events[i].data.fd);
                    //删除节点
                    List_DelNode(list_head,events[i].data.fd);
                    msg_data.type=2;

                    //将断开连接的客户端套接字从epoll函数监听队列里删除调用
                    event.data.fd=events[i].data.fd; //监听的套接字
                    epoll_ctl(epfd,EPOLL_CTL_DEL,events[i].data.fd,&event);
                    close(event.data.fd);
                }
                if(msg_data.type==1) //好友上线的时候保存一次名称
                {
                    //保存名称
                    List_SaveName(list_head,&msg_data,events[i].data.fd);
                }
                //转发消息给其他好友
                msg_data.number=List_GetNodeCnt(list_head); //当前在线好友人数
                Server_SendMsgData(list_head,&msg_data,events[i].data.fd);
            }
        }
    } 
    //退出进程
    signal_work_func(0);
    return 0;
}


/*
函数功能: 创建链表头
*/
struct CLIENT_FD *List_CreateHead(struct CLIENT_FD *list_head)
{
    if(list_head==NULL)
    {
        list_head=malloc(sizeof(struct CLIENT_FD));
        list_head->next=NULL;
    }
    return list_head;
}

/*
函数功能: 添加节点
*/
void List_AddNode(struct CLIENT_FD *list_head,int fd)
{
    struct CLIENT_FD *p=list_head;
    struct CLIENT_FD *new_p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    new_p=malloc(sizeof(struct CLIENT_FD));
    new_p->next=NULL;
    new_p->fd=fd;
    p->next=new_p;
}

/*
函数功能: 删除节点
*/
void List_DelNode(struct CLIENT_FD *list_head,int fd)
{
    struct CLIENT_FD *p=list_head;
    struct CLIENT_FD *tmp;
    while(p->next!=NULL)
    {
        tmp=p;
        p=p->next;
        if(p->fd==fd) //找到了要删除的节点
        {
            tmp->next=p->next;
            free(p);
            break;
        }
    }
}

/*
函数功能: 获取当前链表中有多少个节点
*/
int List_GetNodeCnt(struct CLIENT_FD *list_head)
{
    int cnt=0;
    struct CLIENT_FD *p=list_head;
    while(p->next!=NULL)
    {
        p=p->next;
        cnt++;
    }
    return cnt;
}

/*
函数功能: 转发消息
*/
void Server_SendMsgData(struct CLIENT_FD *list_head,struct MSG_DATA *msg_data,int client_fd)
{
    struct CLIENT_FD *p=list_head;
    while(p->next!=NULL)
    {
        p=p->next;
        if(p->fd!=client_fd)
        {
            write(p->fd,msg_data,sizeof(struct MSG_DATA));
        }
    }
}

/*
函数功能: 保存好友的名称
*/
void List_SaveName(struct CLIENT_FD *list_head,struct MSG_DATA *msg_data,int client_fd)
{
    struct CLIENT_FD *p=list_head;
    while(p->next!=NULL)
    {
        p=p->next;
        if(p->fd==client_fd) //找到在链表里的当前套接字
        {
            strcpy(p->name,msg_data->name);
        }
    }
}


/*
函数功能: 获取好友的名称
*/
void List_GetName(struct CLIENT_FD *list_head,struct MSG_DATA *msg_data,int client_fd)
{
    struct CLIENT_FD *p=list_head;
    while(p->next!=NULL)
    {
        p=p->next;
        if(p->fd==client_fd) //找到在链表里的当前套接字
        {
            strcpy(msg_data->name,p->name);
        }
    }
}