//读取时循环读取，写入时循环写入，使用argv参数
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#define SIZE 123
int main(int argc, char const *argv[])
{
    if(3 != argc)
    {
        printf("输入参数错误，例如：./a.out + 源文件 + 目标文件\n");
        return -1;
    }
    //打开要复制的文件以只读方式打开，打开要粘贴的文件，以写入并创建并且清空
    int fd = open(argv[1],O_RDONLY);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }
    int fd1 = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0664);
    if(-1 == fd1)
    {
        perror("open1");
        return -1;
    }
    //开始读取  ---》边读边写
    while(1)
    {
        //先读
        char buf[SIZE] = {0};//作为数据的中转站
        ssize_t ret = read(fd,buf,sizeof(buf));
        if(-1 == ret)
        {
            perror("read");
            return -1;
        }
        if(0 == ret)
        {
            printf("读取到文件的末尾，退出while循环\n");
            break;
        }
        //写入
        if(-1 == write(fd1,buf,ret))
        {
            perror("write");
            return -1;
        }
    }
    close(fd);
    close(fd1);
    return 0;
}