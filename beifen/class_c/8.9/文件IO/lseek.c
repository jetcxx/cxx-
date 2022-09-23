#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int fd = open(argv[1],O_RDWR|O_CREAT,0664);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }
    //开始进行写入数据
    if(-1 == write(fd,"hello world",11))
    {
        perror("write");
        return -1;
    }
    int ret;
    if(-1 == (ret = lseek(fd,-11,SEEK_END)))
    {
        perror("lseek");
        return -1;
    }
    printf("ret = %d\n",ret);
    char buf[123] ={0};
    if(-1 == read(fd,buf,sizeof(buf)))
    {
        perror("read");
        return -1;
    }
    printf("buf = %s\n",buf);
    return 0;
}