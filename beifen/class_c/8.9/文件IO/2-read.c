#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int fd = open("./1.txt",O_RDWR|O_CREAT,0666);
    if(-1 == fd)
    {
        perror("open");
        printf("errno = %d\n",errno);
        return -1;
    }
    perror("open1");
    char buf[5] = {0};
    if(-1 == read(fd,buf,5))
    {
        perror("read");
        return -1;
    }
    printf("\n读到的值为buf = %s\n",buf);

    if(-1 == close(fd))
    {
        perror("close");
        return -1;
    }
    return 0;
}
