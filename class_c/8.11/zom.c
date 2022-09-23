#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>       
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if(-1 == pid)
    {
        perror("fork");
        return -1;
    }
    if(pid == 0)
    {
        exit(0);    //子进程结束，父进程未结束，子进程就变成了僵尸进程
    }
    else if(pid > 0)
    {
        while(1)
        {
            sleep(1);
        }
    }
    return 0;
}
