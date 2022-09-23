#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>       
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
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
        printf("父进程运行中...\n");
        sleep(5);
        printf("接受成功，接受到子进程的ID号为%d\n",wait(NULL));
        sleep(5);
    }
    return 0;
}
