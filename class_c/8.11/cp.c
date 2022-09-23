#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd = (argv[1],O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return -1;
    }
    int fd1 = (argv[2],O_RDWR|O_CREAT|O_TRUNC,0666);
    if(fd1 == -1)
    {
        perror("open1");
        return -1;
    }
    int len = lseek(fd,0,SEEK_END);
    return 0;
}
