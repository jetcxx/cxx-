//TCP网络编程之服务器
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <pthread.h>
#include <signal.h>
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
void handler(int signum)
{
    waitpid(-1,NULL,WNOHANG);
}
int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }
    int sockfd, acceptfd;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t addrlen = sizeof(serveraddr);
    char buf[N] = {0};
    ssize_t bytes;
    int fd;
    ssize_t num;
    signal(SIGUSR1,handler);
    //第一步：创建套接字
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        ERRLOG("socket error");
    }
    //第二步：填充服务器网络信息结构体
    //inet_addr：将点分十进制ip地址转换为网络字节序的无符号4字节整数
    //atoi：将数字型字符串转换为整形数据
    //htons：将主机字节序转化为网络字节序
    serveraddr.sin_family = AF_INET;
    //注意：ip地址不能随便写，服务器在那个主机中运行，ip地址就是这个主机的
    //如果是自己主机的客户端服务器测试，可以使用127网段的
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));
    //第三步：将套接字与服务器网络信息结构体绑定
    if(bind(sockfd, (struct sockaddr *)&serveraddr, addrlen) == -1)
    {
        ERRLOG("bind error");
    }
    //第四步：将套接字设置为被动监听状态
    if(listen(sockfd, 5) == -1)
    {
        ERRLOG("listen error");
    }
    pid_t pid;
    while(1)
    {
        if((acceptfd = accept(sockfd,(struct sockaddr*)&clientaddr,&addrlen)) ==-1)
        {
            ERRLOG("accept");
        }
        //打印客户端信息
        printf("客户端%s:%d连接了\n", inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
        //创建子进程
        if((pid = fork()) == -1)
        {
            ERRLOG("fork");
        }
        else if(pid > 0)//父进程负责链接
        {
            //wait(NULL);
            //waitpid(-1,NULL,WNOHANG);
        }
        else if(pid == 0)//子进程负责通信
        {
            while(1)
            {
                if((bytes = recv(acceptfd,buf,N,0)) == -1)
                {
                    ERRLOG("recv");
                }
                else if(bytes == 0)
                {
                    printf("客户端%s:%d退出了\n", inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
                    kill(getppid(),SIGUSR1);
                    exit(1);
                }
                if(strcmp(buf,"quit") == 0)
                {
                    printf("客户端%s:%d退出了\n", inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
                    kill(getppid(),SIGUSR1);
                    exit(1);
                }
                printf("客户端%s:%d收到了消息：%s\n",inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port),buf);
                strcat(buf,"*_*");
                if(send(acceptfd,buf,N,0) == -1)
                {
                    ERRLOG("Send");
                }
            }
        }
    }
    return 0;
}