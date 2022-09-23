#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void Myfun(int SignNum)
{
    printf("自动出牌了\n");
    alarm(5);
}

int main(int argc, char const *argv[])
{
    if(SIG_ERR == signal(SIGALRM,Myfun))
    {
        perror("alarm");
        return -1;
    }
    alarm(5);
    while(1)
    {
        char ch;
        getchar();
        printf("请出牌\n");
        scanf("%c",&ch);
        alarm(5);
    }
    return 0;
}
