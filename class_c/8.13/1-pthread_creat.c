#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* MyFun(void *arg)
{
    int *p = (int *)arg;
    *p = 200;
    printf("我是第一个线程\n");
    printf("子线程获取A的值为:%d\n",*p);
}

int main(int argc, char const *argv[])
{
    int a = 100;
    pthread_t tid = 0;
    if(pthread_create(&tid,NULL,MyFun,&a) != 0)
    {
        printf("线程创建失败\n");
        return -1;
    }
    printf("线程号为:%ld\n",tid);
    printf("1主线程获取的A的值为:%d\n",a);
    sleep(1);
    printf("2主线程获取A的值为:%d\n",a);
    return 0;
}
