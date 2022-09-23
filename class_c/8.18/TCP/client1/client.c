//TCP网络编程之客户端
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
#define N 128
#define ERRLOG(errmsg) do{\
                            perror(errmsg);\
                            printf("%s - %s - %d\n", __FILE__, __func__,__LINE__);\
                            exit(1);\
                            }while(0)
typedef struct{
    int n;//文件内容的大小
    char text[N]; //文件内容
}MSG;

int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }
    int sockfd;
    struct sockaddr_in serveraddr;
    socklen_t addrlen = sizeof(serveraddr);
    char buf[N] = {0};
    char filename[N] = {0};
    int fd;
    MSG msg;
    //第一步：创建套接字
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        ERRLOG("socket error");
    }
    //第二步：填充服务器网络信息结构体
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));
    //第三步：给服务器发送客户端的连接请求
    if(connect(sockfd, (struct sockaddr *)&serveraddr, addrlen) == -1)
    {
        ERRLOG("connect error");
    }
    while(1)
    {
PRINTFILE:
    //客户端输入文件名并发送给服务器
    printf("请输入要下载的文件名: ");
    fgets(filename, N, stdin);
    filename[strlen(filename) - 1] = '\0';
    if(send(sockfd, filename, N, 0) == -1)
    {
        ERRLOG("send error");
    }
    //接收服务器发送的数据并做出相应的处理
    if(recv(sockfd, buf, N, 0) == -1)
    {
        ERRLOG("recv error");
    }
    //如果文件不存在，则重新输入
    if(strcmp(buf, "**NOEXIST**") == 0)
    {
        printf("文件%s不存在，请重新输入!!!\n", filename);
        goto PRINTFILE;
    }
    //如果文件存在，创建或者打开文件
    if((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
    {
        ERRLOG("open error");
    }
    int num;
    //接收服务器发送的数据并写入到文件中
#if 0
    while((num = recv(sockfd, buf, N, 0)) != -1)
   {
      if(strcmp(buf, "**OVER**") == 0)
     {
        break;
     }
      write(fd, buf, num);
   }
#endif
    while(recv(sockfd, &msg, sizeof(msg), 0) != -1)
    {
        if(msg.n > 0)
        {
            write(fd, msg.text, msg.n);
        }
        else if(msg.n == 0)
        {
            break;
        }
    }
    printf("文件下载完毕\n");
    }
    return 0;
}