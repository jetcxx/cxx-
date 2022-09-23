#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd = open("./1.txt",O_RDWR|O_CREAT,0666);//打开一个文件
    if(-1 == fd)
    {
        perror("open");//打印错误信息
        printf("errno = %d\n",errno);
        return -1;
    }
    perror("open1");
    //开始读取数据
    char buf[3] = {0};
    if(-1 == read(fd,buf,3))
    {
        perror("read");
        return -1;
    }
    printf("\n读到的值为buf = %s\n",buf);
    //关闭文件描述符
    if(-1 == close(fd))
    {
        perror("close");
        return -1;
    }
    return 0;
}