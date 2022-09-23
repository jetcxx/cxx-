#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void Myfun(int signum)
{
    printf("哈哈，关不掉我吧！\n");
}
int main(int argc, const char *argv[])
{
    //注册信号函数
    //进行信号捕捉
    if(signal(SIGINT,Myfun) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }
    while(1)
    {
        printf("主线程正在干自己的事情\n");
        sleep(1);
    }
    return 0;
}