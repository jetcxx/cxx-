#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void Myfun(int SignNum)
{
    pid_t pid = wait(NULL);
    printf("回收成功，进程ID为%d\n",pid);
    printf("signnum = %d\n",SignNum);
}

int main(int argc, char const *argv[])
{
    if(signal(SIGCHLD,Myfun) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }
    pid_t pid = fork();
    if(-1 == pid)
    {
        perror("fork");
        return -1;
    }
    else if(pid == 0)
    {
        sleep(3);
        exit(0);
    }
    else if(pid > 0)
    {
        while(1)
        {
            printf("父进程在干自己的事\n");
            sleep(1);
        }
    }
    
    return 0;
}
