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
    int sockfd, acceptfd;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t addrlen = sizeof(serveraddr);
    char buf[N] = {0};
    ssize_t bytes;
    int fd;
    ssize_t num;
    MSG msg;
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
NEXT:
    //第五步：阻塞等待客户端的连接
    if((acceptfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen)) == -1)
    {
        ERRLOG("accept error");
    }
    //打印客户端的信息
    printf("客户端%s:%d连接了\n", inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
    while(1)
    {
RECV:
        //服务器接收客户端发送的内容
        if((bytes = recv(acceptfd, buf, N, 0)) == -1)
        {
            ERRLOG("recv error");
        }
        else if(bytes == 0)
        {
            printf("客户端%s-%d退出了\n", inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
            goto NEXT;
        }
        //printf("filename: %s\n", buf);
        //判断文件是否存在
        if((fd = open(buf, O_RDONLY)) == -1)
        {
            //通过errno来获取文件不存在的错误码，将其单独操作
            //printf("errno = %d\n", errno);
            if(errno == ENOENT)
            {
                //如果文件不存在，服务器告知客户端
                if(send(acceptfd, "**NOEXIST**", N, 0) == -1)
                {
                    ERRLOG("send error");
                }
                goto RECV;
            }
            else
            {
                ERRLOG("open error");
            }
        }
        //如果文件存在也要告知客户端
        if(send(acceptfd, "**EXIST**", N, 0) == -1)
        {
            ERRLOG("send error");
        }
            //TCP数据粘包问题
            //TCP底层有一个Nagel算法，会将一段时间内连续发送的内容组成
            //一个整体，然后再将其发送给接收方，但是接收方接收数据时没有
            //办法区分数据的类型，所以可能会将不同类型的数据一次性接收到，
            //代码就会出现冲突
            //处理方法1：将不能类型的数据通过延时处理，不将其放在一个数据包中发送
#if 0
    //读取文件内容并发送给客户端
    while((num = read(fd, buf, N)) != 0)
   {
      if(send(acceptfd, buf, num, 0) == -1)
     {
        ERRLOG("send error");
     }
   }
    sleep(1);
    //发送结束标志，告知客户端文件内容发送完毕
    if(send(acceptfd, "**OVER**", N, 0) == -1)
   {
      ERRLOG("send error");
   }
#endif
        //处理方法2：只要保证每次发送的数据包都一样大，就不会出现这个问题，
        //定义一个结构体，发送和接收结构体，这样保证每一个单独的数据包都一样大
        while((num = read(fd, buf, N)) != 0)
        {
            msg.n = num;
            strcpy(msg.text, buf);
            if(send(acceptfd, &msg, sizeof(msg), 0) == -1)
            {
                ERRLOG("send error");
            }
        }
        //发送结束标志，告知客户端文件内容发送完毕
        msg.n = 0;
        strcpy(msg.text, "**OVER**");
        if(send(acceptfd, &msg, sizeof(msg), 0) == -1)
        {
            ERRLOG("send error");
        }
        printf("文件发送完毕\n");
    }
    return 0;
}