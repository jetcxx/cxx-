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
#include <sys/select.h>
#include <sys/time.h>
#include <poll.h>
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
    int sockfd, acceptfd;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t addrlen = sizeof(serveraddr);
    char buf[N] = {0};
    ssize_t bytes;
    int fd;
    ssize_t num;
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
    mkfifo("myfifo",0664);
    int fifofd;
    if((fifofd = open("myfifo",O_RDWR)) == -1)
    {
        ERRLOG("open");
    }
    //使用poll函数实现IO多路复用
    //第一步 定义结构体数组
    //结构体数组元素的个数由操作的文件描述符的个数决定
    struct pollfd myfd[3];
    //第二步：给结构体数组的每一个元素赋值
    myfd[0].fd = 0;
    myfd[0].events = POLLIN;//将请求的事件设置为有数据可读
    myfd[1].fd = sockfd;
    myfd[1].events = POLLIN;//将请求的事件设置为有数据可读
    myfd[2].fd = fifofd;
    myfd[2].events = POLLIN;//将请求的事件设置为有数据可读
    int nfds = 3;
    while(1)
    {
        //使用epoll函数等待文件描述符准备就绪
        if(poll(myfd,nfds,-1) == -1)
        {
            ERRLOG("poll");
        }
        //如果有文件描述符准备就绪，则poll函数立即返回
        //判断每一个文件描述符对应的返回的事件是否跟跟踪的请求事件的标志位一致
        if(myfd[0].revents & POLLIN == 1)
        {
            if(fgets(buf,N,stdin) == NULL)
            {
                ERRLOG("fgets");
            }
            buf[strlen(buf) - 1] = '\0';
            printf("buf = %s\n",buf);
        }
        if(myfd[1].revents & POLLIN == 1)
        {
            if((acceptfd = accept(sockfd, (struct sockaddr *)&clientaddr,&addrlen)) == -1)
            {
                ERRLOG("accept error");
            }
            printf("客户端%s:%d连接了\n", inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
        }
        if(myfd[2].revents & POLLIN == 1)
        {
            if(read(fifofd,buf,N) == -1)
            {
                ERRLOG("read");
            }
            printf("fifo:%s\n",buf);
        }
    }
    return 0;
}