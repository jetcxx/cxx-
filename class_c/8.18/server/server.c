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
    struct sockaddr_in  serveraddr,clientaddr;
    //填充服务器网络信息结构体
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));
    socklen_t addrlen = sizeof(serveraddr);
    //第三部：将套接字与服务器网络信息结构体进行绑定
    if(bind(sockfd,(struct sockaddr *)&serveraddr,addrlen) == -1)
    {
        perror("bind");
        return -1;
    }
    //将套接字设置为被动监听状态
    if(listen(sockfd,5) == -1)
    {
        perror("listen");
        return -1;
    }
    //第五步：阻塞等待客户端的链接
    int fd;
NEXT:
    fd = accept(sockfd,(struct sockaddr *)&clientaddr,&addrlen);
    if(fd == -1)
    {
        perror("accept");
        return -1;
    }
    printf("客户端%s:%d连接了\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));

    //进行通信
    int bytes;
    char buf[N];
    while(1)
    {
        bytes = recv(fd,buf,N,0);
        if(bytes == -1)
        {
            ERRLOG("recv");
        }
        else if(bytes == 0)
        {
            printf("客户端%s:%d退出了\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
            goto NEXT;
        }
        if(strcmp(buf,"quit") == 0)
        {
            printf("客户端%s:%d退出了\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
            goto NEXT;
        }
        if(strcmp(buf,"1.txt") == 0)
        {
            printf("文件存在,准备发送\n");
            FILE *fp = fopen("1.txt","r");
            int flag;
            char ptr[N] = {0};
            if(fread(&ptr,sizeof(ptr),1,fp) == 0)
            {
                ERRLOG("fread");
            }
            if(send(fd,ptr,N,0) == -1)
            {
                perror("send");
            }
        }
        else
        {
            printf("文件不存在，返回\n");
            goto NEXT;
        }
        //printf("客户端%s:%d发来了消息：\n %s\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port),buf);strcat(buf,"^_-");
        if(send(fd,buf,N,0) == -1)
        {
            ERRLOG("send error");
        }
    }
    return 0;
}