#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define N 128
#define ERRLOG(errmsg) do{\
                            perror(errmsg);\
                            printf("%s - %s - %d\n",__FILE__,__func__,__LINE__);\
                            exit(1);\
                            }while(0)

int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage: %s <ip> <port>\n",argv[0]);
        exit(1);
    }
    //第一步：创建套接字
    int sockfd;
    struct sockaddr_in serveraddr,clientaddr;
    int addrlen = sizeof(serveraddr);
    if((sockfd = socket(AF_INET,SOCK_DGRAM,0)) == -1)
    {
        ERRLOG("socket error");
    }
    //第二步：填充网络信息结构体
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = intet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));
    //第三步：将套接字与服务器网络信息结构体绑定
    if(bind(sockfd,(struct sockaddr *)&serveraddr,addrlen) == -1)
    {
        ERRLOG("bind");
    }
    //进行通信
    char buf[N] = {0};
    while(1)
    {
NEXT:
        if(recvfrom(sockfd,buf,N,0,(struct sockaddr *)&clientaddr,&addrlen) == -1)
        {
            ERRLOG("recvfrom");
        }
        if(strcmp(buf,"quit") == 0)
        {
            printf("客户端%s-%d退出了\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
            goto NEXT;
        }
        printf("客户端%s-%d发来消息:%s\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
        strcat(buf,"*_*");
        if(sendto(sockfd,buf,N,0,(struct sockaddr *)&clientaddr,addrlen) == -1)
        {
            ERRLOG("sendto");
        }
    }
    return 0;
}
