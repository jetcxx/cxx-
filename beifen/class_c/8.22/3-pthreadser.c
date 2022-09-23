//TCP网络编程之服务器
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
#include <pthread.h>
#define N 128
#define ERRLOG(errmsg) do{\
                            perror(errmsg);\
                            printf("%s - %s - %d\n", __FILE__, __func__,__LINE__);\
                            exit(1);\
                            }while(0)

typedef struct{
    int acceptfd;
    struct sockaddr_in clientaddr;
}Msg;

struct sockaddr_in serveraddr, clientaddr;
socklen_t adderlen = sizeof(serveraddr);

void * pthreadRun(void *arg)
{
    char buf[N] = {0};
    ssize_t bytes;
    Msg msg = *(Msg *)arg;
    while(1)
    {
        if((bytes = recv(msg.acceptfd,buf,N,0)) == -1)
        {
            ERRLOG("recv");
        }
        else if(bytes == 0)
        {
            printf("客户端%s:%d退出了\n", inet_ntoa(msg.clientaddr.sin_addr),
            ntohs(msg.clientaddr.sin_port));
            pthread_exit(NULL);
        }
        if(strcmp(buf,"quit") == 0)
        {
            printf("客户端%s:%d退出了\n", inet_ntoa(msg.clientaddr.sin_addr),
            ntohs(msg.clientaddr.sin_port));
            pthread_exit(NULL);
        }
        printf("客户端%s:%d收到了消息：%s\n", inet_ntoa(msg.clientaddr.sin_addr),ntohs(msg.clientaddr.sin_port),buf);strcat(buf,"*_*");
        if(send(msg.acceptfd,buf,N,0) == -1)
        {
            ERRLOG("Send");
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

    int sockfd,acceptfd;
    if(sockfd = socket(AF_INET,SOCK_STREAM,0) == -1)
    {
        ERRLOG("socket error");
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if(bind(sockfd,(struct sockaddr *)&serveraddr,adderlen) == -1)
    {
        ERRLOG("bind error");
    }

    if(listen(sockfd,5) == -1)
    {
        ERRLOG("listen error");
    }

    while(1)
    {
        if(acceptfd = accept(sockfd,(struct sockaddr*)&clientaddr,&adderlen) == -1)
        {
            ERRLOG("accept error");
        }
        printf("客户端%s:%d连接了\n", inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));

        pthread_t thread;
        Msg msg;
        msg.acceptfd = acceptfd;
        msg.clientaddr = clientaddr;
        if(pthread_create(&thread,NULL,pthreadRun,&msg) != 0)
        {
            ERRLOG("pthread_create");
        }
    }
    return 0;
}
