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
#include <sys/select.h>
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
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t adderlen = sizeof(serveraddr);
    char buf[N] = {0};
    ssize_t bytes;
    int fd;
    ssize_t num;

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

    fd_set readfds;
    FD_ZERO(&readfds);
    int maxfd = sockfd;
    FD_SET(sockfd,&readfds);

    while(1)
    {
        
        if(select(maxfd + 1,&readfds,NULL,NULL,NULL) == -1)
        {
            ERRLOG("select");
        }
        if(FD_ISSET(0,&readfds) == 1)
        {
            fgets(buf,N,stdin);
            buf[strlen(buf) - 1] = '\0';
            printf("buf = %s\n",buf);
        }
        if(FD_ISSET(sockfd,&readfds) == 1)
        {
            printf("1111\n");
            if((acceptfd = accept(sockfd, (struct sockaddr *)&clientaddr,&adderlen)) == -1)
            {
                ERRLOG("accept error");
            }
            printf("客户端%s:%d连接了\n", inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
        }
    }
    return 0;
}
