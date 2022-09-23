#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#define N 128
#define ERRLOG(errmsg) do{\
perror(errmsg);\
printf("%s - %s - %d\n",__FILE__,__func__,__LINE__);\
exit(1);\
}while(0)

int main(int argc, const char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage:%s <ip> <port>\n",argv[0]);
        exit(1);
    }
    int sockfd;
    //第一步：创建套接字
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sockfd)
    {
        perror("socket error");
        exit(1);
    }
    struct sockaddr_in  serveraddr;
    //第二步：填充服务器网络信息结构体
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));
    socklen_t addrlen = sizeof(serveraddr);
    //第三步：给服务器发送客户端的链接请求
    if(connect(sockfd,(struct sockaddr *)&serveraddr,addrlen) == -1)
    {
        perror("connect error");
        exit(1);
    }
    char buf[N] = {0};
    while(1)
    {
        fgets(buf,N,stdin);
        buf[strlen(buf)-1] = '\0';
        FILE *fp1 = fopen("1.txt","a");
        
        
        if(send(sockfd,buf,N,0) == -1)
        {
            ERRLOG("send");
        }
        if(strcmp(buf,"quit") == 0)
        {
            printf("客户端退出了\n");
            exit(0);
        }
        memset(buf,0,N);
        if(recv(sockfd,buf,N,0) == -1)
        {
            ERRLOG("RECV");
        }
        fwrite(&buf,N,N,fp1);
        //printf("服务器：%s\n",buf);
    }
    return 0;
}