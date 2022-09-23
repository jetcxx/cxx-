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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/select.h>
#include <sys/time.h>
#include <poll.h>
#include <sys/epoll.h>

//消息结构体
struct MSG_DATA
{
    char type; //消息类型.  0表示有聊天的消息数据  1表示好友上线  2表示好友下线
    char name[50]; //好友名称
    int number;   //在线人数的数量
    unsigned char buff[100];  //发送的聊天数据消息
};
struct MSG_DATA msg_data;

#define MAX_EVENTS 2
struct epoll_event ev, events[MAX_EVENTS];
int epollfd;
int nfds;

//文件接收端
int main(int argc,char **argv)
{   
    if(argc!=4)
    {
        printf("./app  <IP地址> <端口号> <名称>\n");
        return 0;
    }
    int sockfd;
    //忽略 SIGPIPE 信号--方式服务器向无效的套接字写数据导致进程退出
    signal(SIGPIPE,SIG_IGN); 

    /*1. 创建socket套接字*/
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    /*2. 连接服务器*/
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(atoi(argv[2])); // 端口号0~65535
    addr.sin_addr.s_addr=inet_addr(argv[1]); //IP地址
    if(connect(sockfd,(const struct sockaddr *)&addr,sizeof(struct sockaddr_in))!=0)
    {
        printf("客户端:服务器连接失败.\n");
        return 0;
    }

    /*3. 发送消息表示上线*/
    msg_data.type=1;
    strcpy(msg_data.name,argv[3]);
    write(sockfd,&msg_data,sizeof(struct MSG_DATA));

    int cnt;
    int i;
    //创建专用文件描述符
    epollfd = epoll_create(10);
    //添加要监听的文件描述符
    ev.events = EPOLLIN;
    ev.data.fd = sockfd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev);

    ev.events = EPOLLIN;
    ev.data.fd = 0; //标准输入文件描述符
    epoll_ctl(epollfd, EPOLL_CTL_ADD, 0, &ev);

    while(1)
    {
        //监听事件
        nfds=epoll_wait(epollfd,events,MAX_EVENTS,-1);
        if(nfds)
        {
            for(i=0;i<nfds;i++)
            {
                if(events[i].data.fd==sockfd) //判断收到服务器的消息
                {
                    cnt=read(sockfd,&msg_data,sizeof(struct MSG_DATA));
                    if(cnt<=0) //判断服务器是否断开了连接
                    {
                        printf("服务器已经退出.\n");
                        goto SERVER_ERROR;
                    }
                    else if(cnt>0)
                    {
                        if(msg_data.type==0)
                        {
                            printf("%s:%s  在线人数:%d\n",msg_data.name,msg_data.buff,msg_data.number);
                        }
                        else if(msg_data.type==1)
                        {
                            printf("%s 好友上线. 在线人数:%d\n",msg_data.name,msg_data.number);
                        }
                        else if(msg_data.type==2)
                        {
                            printf("%s 好友下线. 在线人数:%d\n",msg_data.name,msg_data.number);
                        }
                    }
                }
                else if(events[i].data.fd==0) //表示键盘上有数据输入
                {
                    gets(msg_data.buff); //读取键盘上的消息
                    msg_data.type=0; //表示正常消息
                    strcpy(msg_data.name,argv[3]); //名称
                    write(sockfd,&msg_data,sizeof(struct MSG_DATA));
                }
            }
        }
    }
SERVER_ERROR:
    close(sockfd);
    return 0;
}