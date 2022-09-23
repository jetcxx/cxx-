#include "server.h"



sqlite3 *usrdb;
sqlite3 *onlinedb;
int sockfd;

int setnonblockint(int sockfd) 
{
    int old_option = fcntl(sockfd, F_GETFL);
	int new_option = old_option | O_NONBLOCK;
	fcntl(sockfd, F_SETFL, new_option);
	return old_option;
}

void addfd(int epollfd, int sockfd, int enable_et)
{
    struct epoll_event event;
	event.data.fd = sockfd;
	event.events  = EPOLLIN;
	if(enable_et)
    {
		event.events |= EPOLLET;
	}
	epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &event );
	setnonblockint(sockfd);
}

/*int tcp_accept(int sfd)
{
    struct sockaddr_in clientaddr;
    memset(&clientaddr,0,sizeof(struct sockaddr));
    int addrlen = sizeof(struct sockaddr);
    int new_fd = accept(sfd,(struct sockaddr *)&clientaddr,&addrlen);
    if(new_fd == -1)
    {
        perror("accept");
        close(sfd);
        exit(-1);
    }
    printf("%s %d success connect...\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
    return new_fd;
}*/


int VerifyUsernameExists(char *username)
{
    char username1[10] = {0};
    strcpy(username1,username);
    int ret = sqlite3_open("UserInformation.db",&usrdb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(usrdb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(usrdb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        //printf("**************\n");
        printf("sqlite3_get_table:%s",sqlite3_errmsg(usrdb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    for(int i = 1;i <= row;i++)
    {
        if(strcmp(username1,result[i*column]) != 0)
        {
            continue;
        }
        if(strcmp(username1,result[i*column]) == 0)
        {
            printf("此用户名已被使用\n");
            return 1;
            break;
        }
    }
    printf("此用户名可用\n");
    return 2;
}






//注册
int enroll(char *username,char *passwd)
{
    int ret = sqlite3_open("UserInformation.db",&usrdb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(usrdb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"create table if not exists user(username char,passwd char);");
    ret = sqlite3_exec(usrdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n",sqlite3_errmsg(usrdb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    sprintf(sql,"insert into user values('%s','%s');",username,passwd);
    ret = sqlite3_exec(usrdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s",sqlite3_errmsg(usrdb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    printf("%s注册操作结束\n",username);
    return 1;
}

//登录时检验用户名是否存在
int VerifyUsername(char *username)
{
    char username1[10] = {0};
    strcpy(username1,username);
    printf("%s\n",username1);
    int ret = sqlite3_open("UserInformation.db",&usrdb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(usrdb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(usrdb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s",sqlite3_errmsg(usrdb));
        return -1;
    }
    //printf("%d %d\n",row,column);
    //printf("%s\n",result[1*column]);
    for(int i = 1;i <= row;i++)
    {
        int t = strcmp(username1,result[i*column]);
        if(t != 0)
        {
            continue;
        }
        if(t == 0)
        {
            //printf("用户存在\n");
            return 1;
            break; 
        }        
    }
    //printf("未查询到此用户\n");
    return -1;
}

//登录时检验用户名是否已登录
int VerifyUserisloggedin(char *username)
{
    char username1[10] = {0};
    strcpy(username1,username);

    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    memset(sql,0,sizeof(sql));
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(onlinedb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        //printf("**************\n");
        printf("sqlite3_get_table:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    for(int i = 1;i <= row;i++)
    {
        if(strcmp(username1,result[i*column]) == 0)
        {
            printf("不要重复登录\n");
            return 1;
            break;
        }
    }
    printf("可登录\n");
    return 2;
}


int VerifyPassword(char *passwd)
{
    char passwd1[100] = {0};
    strcpy(passwd1,passwd);
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    int ret = sqlite3_get_table(usrdb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s",sqlite3_errmsg(usrdb));
        return -1;
    }
    for(int i = 1;i <= row;i++)
    {
        int k = strcmp(passwd1,result[i*column+1]);
        if(k != 0)
        {
            continue;
        }
        if(k == 0)
        {
            printf("登陆成功，请稍后......\n");
            return 1; 
            break;
        }
    }
    printf("密码错误，重新输入\n");
    return -1;
}

int Saveonlineuser(char *username,int fd)
{
    //printf("fd = %d\n",fd);
    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"create table if not exists user(username char,fd int);");
    ret = sqlite3_exec(onlinedb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    sprintf(sql,"insert into user values('%s','%d');",username,fd);
    ret = sqlite3_exec(onlinedb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    printf("录入结束\n");
}


int DeleteOnlineUser(char *username)
{
    printf("%s\n",username);
    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(onlinedb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_get_table:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    sprintf(sql,"delete from user where username = '%s';",username);
    ret = sqlite3_exec(onlinedb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    printf("已删除记录\n");
    return 1;
}


int Privatechat(char *username,char *buf,char *sender)
{
    printf("进入私聊函数\n");
    char username1[10] = {0};
    char buf1[100] = {0};
    char sender1[10] = {0};
    strcpy(username1,username);
    strcpy(buf1,buf);
    strcpy(sender1,sender);
    //printf("%s,%s,%s\n",username1,buf1,sender1);

    strcpy(msg_data.buff,buf1);
    strcpy(msg_data.cmd,"chatone");
    strcpy(msg_data.sender,sender1);
    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(onlinedb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        //printf("**************\n");
        printf("sqlite3_get_table:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    for(int i = 1;i <= row;i++)
    {
        if(strcmp(username1,result[i*column]) == 0)
        {
            printf("找到此在线用户\n");
            int fd = atoi(result[i*column+1]);
            printf("fd = %d",fd);
            send(fd,&msg_data,sizeof(msg_data),0);
        }
    }
    //printf("此用户不在线\n");
}

int Mass(char *sender,char *buf)
{
    char sender1[10] = {0};
    char buf1[100] = {0};
    strcpy(sender1,sender);
    strcpy(buf1,buf);

    strcpy(msg_data.sender,sender1);
    strcpy(msg_data.buff,buf1);
    strcpy(msg_data.cmd,"chatall");
    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(onlinedb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        //printf("**************\n");
        printf("sqlite3_get_table:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    for(int i = 1;i <= row;i++)
    {
        int fd = atoi(result[i*column+1]);
        send(fd,&msg_data,sizeof(msg_data),0);
    }
}

int ViewOnlineUser()
{
    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(onlinedb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        //printf("**************\n");
        printf("sqlite3_get_table:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    memset(&msg_data,0,sizeof(msg_data));
    sleep(1);
    for(int i = 1;i <= row;i++)
    {
        strcat(msg_data.buff,result[i*column]);
    }
    strcpy(msg_data.cmd,"ViewOnlineUser");
    return 1;
}


int ViewChathistory()
{
    char buf[100] = {0};
    FILE *fp2 = fopen("Chatallhistory.txt","r");
    if(fp2 == NULL)
    {
        ERRLOG("fopen");
    }
    if(0 == fread(&buf,sizeof(buf),1,fp2))
    {
        ERRLOG("fread");
    }
    fclose(fp2);
    strcpy(msg_data.buff,buf);
    strcpy(msg_data.cmd,"ViewChathistory");
    return 1;
}

int Kick(char *kickname)
{
    char kickname1[10] = {0};
    strcpy(kickname1,kickname);
    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(onlinedb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_get_table:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    for(int i = 1;i <= row;i++)
    {
        if(strcmp(kickname1,result[i*column]) == 0)
        {
            printf("找到此在线用户\n");
            int fd = atoi(result[i*column+1]);
            strcpy(msg_data.username,kickname1);
            strcpy(msg_data.cmd,"kicked");
            //printf("fd = %d",fd);
            send(fd,&msg_data,sizeof(msg_data),0);
        }
    }
}

int Silence(char *username)
{
    char Silenceusername[10] = {0};
    strcpy(Silenceusername,username);
    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(onlinedb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_get_table:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    for(int i = 1;i <= row;i++)
    {
        if(strcmp(Silenceusername,result[i*column]) == 0)
        {
            printf("找到此在线用户\n");
            int fd = atoi(result[i*column+1]);
            strcpy(msg_data.username,Silenceusername);
            strcpy(msg_data.cmd,"silenced");
            //printf("fd = %d",fd);
            send(fd,&msg_data,sizeof(msg_data),0);
        }
    }
}

int Logout(char *username)
{
    char username1[10] = {0};
    strcpy(username1,username);

    int ret = sqlite3_open("UserInformation.db",&usrdb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(usrdb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(usrdb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s",sqlite3_errmsg(usrdb));
        return -1;
    }
    memset(&sql,0,sizeof(sql));
    sprintf(sql,"delete from user where username = '%s';",username1);
    ret = sqlite3_exec(usrdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n",sqlite3_errmsg(usrdb));
        return -1;
    }
    printf("已从数据库表中删除此用户\n");
    return 1;
}

int Lifting(char *username)
{
    char username1[10] = {0};
    strcpy(username1,username);
    int ret = sqlite3_open("OnlineUser.db",&onlinedb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(onlinedb));
        return -1;
    }
    char sql[128] = {0};
    sprintf(sql,"select *from user;");
    char **result;
    int row,column;
    ret = sqlite3_get_table(onlinedb,sql,&result,&row,&column,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_get_table:%s",sqlite3_errmsg(onlinedb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    for(int i = 1;i <= row;i++)
    {
        if(strcmp(username1,result[i*column]) == 0)
        {
            printf("找到此在线用户\n");
            int fd = atoi(result[i*column+1]);
            strcpy(msg_data.username,username1);
            strcpy(msg_data.cmd,"Lifting");
            //printf("fd = %d",fd);
            send(fd,&msg_data,sizeof(msg_data),0);
        }
    }
}














int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    
    int clientfd;
    struct sockaddr_in serveraddr,clientaddr;
    socklen_t addrlen = sizeof(serveraddr);
    char buf[1000] = {0};


    sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockfd == -1)
    {
        ERRLOG("socket error");
    }
    else
    {
        printf("socket success!\n");
    }
    memset(&serveraddr, 0, sizeof(struct sockaddr_in));

    //int iflags = fcntl(sockfd,F_GETFL,0);
    //fcntl(sockfd,F_SETFL,O_NONBLOCK | iflags);
    
    /*int on = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) 
    {
        ERRLOG("setsockopt error");
    }*/

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if(bind(sockfd,(struct sockaddr *)&serveraddr,addrlen) == -1)
    {
        ERRLOG("bind error");
    }
    else
    {
        printf("bind success!\n");
    }
    

    if(listen(sockfd,5) == -1)
    {
        ERRLOG("listen error");
    }
    else
    {
        printf("listen success!\n");
    }
    

    int epfd = epoll_create(1);
    if(epfd == -1)
    {
        ERRLOG("epoll create error");
    }
    else
    {
        printf("epoll success!\n");
    }
    

    struct epoll_event ev,events[100] ={0};


    ev.data.fd = sockfd;
    ev.events = EPOLLIN;


    int ret;
    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&ev);
    if(ret == -1)
    {
        ERRLOG("epoll ctl error");
    }

    int i;


    while(1)
    {
        int nready = epoll_wait(epfd,events, 1000, -1); // 阻塞等待结点变化
        for(int i = 0; i < nready; i++)
        {
            if(!(events[i].events & EPOLLIN))
            continue; // 只要有事件发生，就会计入ep[]中，如果不是读事件，继续循环
            if(events[i].data.fd == sockfd)
            {
                // 连接请求
                int cfd = accept(sockfd, (struct sockaddr*)&clientaddr, &addrlen);
                char ip[16] = {0};
                printf("connect from %s at %d\n", inet_ntop(AF_INET, &clientaddr.sin_addr.s_addr, ip, sizeof(ip)), ntohs(clientaddr.sin_port)); // 打印客户端信息
                // cfd 上树
                ev.data.fd = cfd;
                ev.events = EPOLLIN;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
            }
            else
            {
                // 普通读事件
                int sockfd = events[i].data.fd;
                //char buf[BUFSIZ] = {0};

                //接受数据!!!!
                int n = read(sockfd,&msg_data, sizeof(msg_data));
                if(n < 0)
                {    
                    perror("read err");
                    epoll_ctl(epfd, EPOLL_CTL_DEL, sockfd, NULL); // 下树
                    close(sockfd);
                }
                else if(n == 0)
                { 
                    printf("client[%d] closed\n", sockfd);
                    epoll_ctl(epfd, EPOLL_CTL_DEL, sockfd, NULL); // 下树
                    close(sockfd);
                }
                else
                {
                    
                    //传入命令！！！
                    write(sockfd,msg_data.cmd,sizeof(msg_data.cmd));
                    //printf("sockfd = %d\n",sockfd);
                    //write(sockfd,&msg_data,sizeof(msg_data));
                    //判断命令为注册
                    if (strcmp(msg_data.cmd,"enroll") == 0)
                    {
                        //printf("112121121212\n");
                        char username[10] ={0};
                        char passwd[100] = {0};
                        //memset(msg_data.username,0,sizeof(msg_data.username));
                        //memset(msg_data.passwd,0,sizeof(msg_data.passwd));
                        strcpy(username,msg_data.username);
                        strcpy(passwd,msg_data.passwd);
                        int t = enroll(username,passwd);
                        if(t == 1)
                        {
                            //memset(msg_data.cmd,0,sizeof(msg_data.cmd));
                            strcpy(msg_data.cmd,"passenroll");
                            //sprintf(msg_data.cmd,"passenroll");
                            send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                        }
                    }

                    if(strcmp(msg_data.cmd,"VerifyUsernameExists") == 0)
                    {
                        char username[10] = {0};
                        strcpy(username,msg_data.username);
                        int t = VerifyUsernameExists(username);
                        if(t == 2)
                        {
                            strcpy(msg_data.cmd,"VerifyUsernameExistsPass");
                        }
                        if(t == 1)
                        {
                            strcpy(msg_data.cmd,"VerifyUsernameExistsAgain");
                        }
                        send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                    }




                    //登录(验证用户名)
                    if(strcmp(msg_data.cmd,"login") == 0)
                    {
                        char username[10] = {0};
                        //memset(msg_data.username,0,sizeof(msg_data.username));
                        strcpy(username,msg_data.username);
                        //printf("%s\n",username);
                        int t = VerifyUsername(username);
                        //printf("%d\n",t);
                        if(t == -1)
                        {
                            //memset(msg_data.cmd,0,sizeof(msg_data.cmd));
                            strcpy(msg_data.cmd,"loginusrnameagain");
                            send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                        }
                        if(t == 1)
                        {
                            printf("loginusrnamepass\n");
                            //memset(msg_data.cmd,0,sizeof(msg_data.cmd));
                            strcpy(msg_data.cmd,"loginusrnamepass");
                            strcpy(msg_data.username,username);
                            int y = send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                            printf("%d   send yes\n",y);
                        }

                    }

                    //验证用户是否已登录过
                    if(strcmp(msg_data.cmd,"VerifyUserisloggedin") == 0)
                    {
                        char username[10] = {0};
                        strcpy(username,msg_data.username);
                        int t = VerifyUserisloggedin(username);
                        if(t == 1)
                        {
                            strcpy(msg_data.cmd,"userisloggedinagain");
                        }
                        if(t == 2)
                        {
                            strcpy(msg_data.username,username);
                            strcpy(msg_data.cmd,"userisloggedinpass");
                        }
                        sleep(1);
                        send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                    }




                    //登录验证密码
                    if(strcmp(msg_data.cmd,"VerifyPassword") == 0)
                    {
                        char passwd[100] = {0};
                        char username[10] = {0};
                        strcpy(username,msg_data.username);
                        strcpy(passwd, msg_data.passwd);
                        int t = VerifyPassword(passwd);
                        //printf("%d\n",t);
                        if(t == -1)
                        {
                            memset(msg_data.cmd,0,sizeof(msg_data.cmd));
                            sprintf(msg_data.cmd,"loginpasswdagain");
                            send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                        }


                        if(t == 1 && (strcmp(username,"admin") == 0))
                        {
                            memset(msg_data.cmd,0,sizeof(msg_data.cmd));
                            sprintf(msg_data.cmd,"loginadminpasswdpass");
                            strcpy(msg_data.username,username);
                            send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                            Saveonlineuser(msg_data.username,events[i].data.fd);
                        }
                        else if(t == 1)
                        {
                            memset(msg_data.cmd,0,sizeof(msg_data.cmd));
                            sprintf(msg_data.cmd,"loginpasswdpass");
                            strcpy(msg_data.username,username);
                            send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                            //将登录用户信息保存至数据库
                            Saveonlineuser(msg_data.username,events[i].data.fd);
                            //printf("t = %d\n",t);
                        }
                        
                    }


                    //群发
                    if(strcmp(msg_data.cmd,"mass") == 0)
                    {
                        //printf("massmassmasas1232131312\n");
                        char buf[100] = {0};
                        char sender[10] = {0};
                        strcpy(sender,msg_data.sender);
                        strcpy(buf,msg_data.buff);
                        
                        FILE *fp = fopen("Chatallhistory.txt","a");
                        if(NULL == fp)
                        {
                            ERRLOG("fopen");
                        }
                        if(1 != fwrite(&buf,sizeof(buf),1,fp))
                        {
                            ERRLOG("fwrite");
                        }
                        fclose(fp);
                        Mass(sender,buf);
                        
                    }

                    //私聊
                    if(strcmp(msg_data.cmd,"Privatechat") == 0)
                    {
                        //printf("接收到私聊命令\n");
                        char username[10] = {0};
                        char buf[100] = {0};
                        char sender[10] = {0};
                        strcpy(sender,msg_data.sender);
                        strcpy(username,msg_data.username);
                        strcpy(buf,msg_data.buff);
                        printf("username= %s,buf= %s,sender= %s\n",username,buf,sender);
                        FILE *fp1 = fopen("Chatonehistory.txt","a");
                        if(NULL == fp1)
                        {
                            ERRLOG("fopen");
                        }
                        if(1 != fwrite(&buf,sizeof(buf),1,fp1))
                        {
                            ERRLOG("fwrite");
                        }
                        fclose(fp1);
                        Privatechat(username,buf,sender);
                    }

                    //用户下线从数据库中删掉
                    if(strcmp(msg_data.cmd,"offline") == 0)
                    {
                        //printf("yesyes\n");
                        char username[10] = {0};
                        strcpy(username,msg_data.username);
                        int t = DeleteOnlineUser(username);
                        if(t == 1)
                        {
                            printf("%s已下线\n",username);
                        }
                        //printf("username = %s\n",username);
                    }

                    //查看在线用户
                    if(strcmp(msg_data.cmd,"ViewOnlineUser") == 0)
                    {
                        int t = ViewOnlineUser();
                        if(t == 1)
                        {
                            send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                            //return;
                        }
                        if(t != 1)
                        {
                            ERRLOG("ViewOnlineUser");
                        }
                    }

                    if(strcmp(msg_data.cmd,"ViewChathistory") == 0)
                    {
                        int t = ViewChathistory();
                        if(t == 1)
                        {
                            send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                        }
                    }

                    if(strcmp(msg_data.cmd,"kick") == 0)
                    {
                        char kickname[10] = {0};
                        strcpy(kickname,msg_data.username);
                        Kick(kickname);
                    }

                    if(strcmp(msg_data.cmd,"silence") == 0)
                    {
                        char silenceusername[10] = {0};
                        strcpy(silenceusername,msg_data.username);
                        Silence(silenceusername);
                    }

                    if(strcmp(msg_data.cmd,"logout") == 0)
                    {
                        char username[10] = {0};
                        strcpy(username,msg_data.username);
                        int t = Logout(username);
                        if(t == 1)
                        {
                            strcpy(msg_data.cmd,"logoutsuccess");
                            send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                        }
                    }

                    if(strcmp(msg_data.cmd,"Lifting") == 0)
                    {
                        char username[10] = {0};
                        strcpy(username,msg_data.username);
                        Lifting(username);
                    }
                    
                    if(strcmp(msg_data.cmd,"downloadfile") == 0)
                    {
                        FILE *fp3 = fopen(msg_data.buff,"r");
                        if(fp3 == NULL)
                        {
                            printf("文件不存在\n");
                            strcpy(msg_data.cmd,"fileisnotexist");
                        }
                        else
                        {
                            printf("文件存在\n");
                            fread(msg_data.passwd,sizeof(msg_data.passwd),1,fp3);
                            strcpy(msg_data.cmd,"fileisexist");
                        }
                        send(events[i].data.fd,&msg_data,sizeof(msg_data),0);
                    }
                    //write(STDOUT_FILENO,buf, n);
                }
            }
            // 普通读事件结束
        }
    } 
    //退出进程
    close(sockfd);
    close(epfd);
    return 0;
}
