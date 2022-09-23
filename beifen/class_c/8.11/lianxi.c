#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    //使用文件IO打开文件，获取文件大小
    int fd = open(argv[1],O_RDONLY);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }
    int fd1 = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);
    if(-1 == fd1)
    {
        perror("open1");
        return -1;
    }
    //获取文件大小，利用偏移量
    int len = lseek(fd,0,SEEK_END);
    printf("len = %d\n",len);
    //需要一个从开头，一个从中间开始获取
    len = len / 2;
    pid_t pid = fork();
    if(-1 == pid)
    {
        perror("fork");
        return -1;
    }
    if(pid == 0)
    {
        lseek(fd,len,SEEK_SET);
        lseek(fd1,len,SEEK_SET);
        char buf[123] = {0};  //接收读到的输入，写入数据时使用
        ssize_t ret  =0;
        while((ret = read(fd,buf,123)))
        {
            if(-1 == write(fd1,buf,ret))
            {
                perror("write");
                return -1;
            }
        }
        close(fd);
        close(fd1);
    }
    else if(pid > 0)
    {
        //父进程 ----》从头开始
        lseek(fd,0,SEEK_SET);
        lseek(fd1,0,SEEK_SET);
        char buf[123] = {0};
        ssize_t ret = 0;
        while(len)
        {
            if(len >= 123)
            {
                ret = read(fd,buf,123);
            }
            else
            {
                ret = read(fd,buf,len);
            }
            write(fd1,buf,ret);
            len = len - ret;
        }
    }
    return 0;
}
