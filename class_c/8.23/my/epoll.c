#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/epoll.h>
#define N 128
#define ERRLOG(errmsg) do{\
                            perror(errmsg);\
                            printf("%s - %s - %d\n", __FILE__, __func__,__LINE__);\
                            exit(1);\
                            }while(0)

int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd,acceptfd;
    struct sockaddr_in serveraddr,clientaddr;
    socklen_t addrlen = sizeof(serveraddr);
    char buf[1000] = {0};

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        ERRLOG("socket error");
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if(bind(sockfd,(struct sockaddr *)&serveraddr,addrlen) == -1)
    {
        ERRLOG("bind error");
    }

    if(listen(sockfd,5) == -1)
    {
        ERRLOG("listen error");
    }

    int epfd;
    if(epoll_create(2000) == -1)
    {
        ERRLOG("epoll create error");
    }

    struct epoll_event ev,events[2000] = {0};
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
        int num = epoll_wait(epfd,events,2000,-1);
        if(num == -1)
        {
            ERRLOG("epoll wait error");
        }
        for(i = 0;i < num;i++)
        {
            if(events[i].data.fd == sockfd)
            {
                if(acceptfd = accept(sockfd,(struct sockaddr *)&clientaddr,&addrlen) == -1)
                {
                    ERRLOG("accept error");
                }
                ev.events = EPOLLIN;
                ev.data.fd = acceptfd;
                int ret = epoll_ctl(epfd,EPOLL_CTL_ADD,acceptfd,&ev);
                if(ret == -1)
                {
                    ERRLOG("epoll ctl error");
                }
                printf("客户端%s:%d成功连接\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));              
            }
            else
            {
                if(events[i].events & EPOLLIN)
                {
                    ret = recv(events[i].data.fd,&buf,N,0);
                    if(ret == -1)
                    {
                        ERRLOG("recv error");
                    }
                    else if(ret == 0)
                    {
                        ev.data.fd = events[i].data.fd;
                        ev.events = EPOLLIN;
                        int ret = epoll_ctl(epfd,EPOLL_CTL_ADD,events[i].data.fd,&ev);
                        if(ret == -1)
                        {
                            ERRLOG("epoll ctl error");
                        }
                        close(events[i].data.fd);
                    }
                    else
                    {
                        printf("客户端%s:%d发来消息:%s\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port),buf);
                        memset(buf,0,sizeof(buf));
                    }
                    
                }
            }
            
        }
    }






    return 0;
}
