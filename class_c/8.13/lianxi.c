#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int count = 0;
int flag = 0;

void* MyFun1(void *arg)
{
    while(1)
    {
        if(flag == 0)
        {
            count++;
            flag = 1;
        }
    }
}


int main(int argc, char const *argv[])
{
    
    pthread_t tid = 0;
    if(pthread_create(&tid,NULL,MyFun1,NULL) != 0)
    {
        printf("线程创建失败\n");
        return -1;
    }
    while(1)
    {
        if(flag == 1)
        {
            sleep(1);
            printf("count = %d\n",count);
            flag = 0;
        }
    }
    return 0;
}
