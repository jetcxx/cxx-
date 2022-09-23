#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void * myfun(void * arg)
{
    int i = 500000;
    while(i)
    {
        pthread_mutex_lock(&mutex);
        //临界区 ---》开始
        int a = count;
        a++;
        count = a; 
        //临界区 ---》结束
        pthread_mutex_unlock(&mutex);
        i--;
    }
}
int main(int argc, char const *argv[])
{
    pthread_t tid = 0;
    pthread_create(&tid,NULL,myfun,NULL);
    int i = 500000;
    while(i)
    {
        pthread_mutex_lock(&mutex);
        int a = count;
        a++;
        count = a;
        pthread_mutex_unlock(&mutex);
        i--;
    }
    pthread_join(tid,NULL);
    pthread_mutex_destroy(&mutex);
    printf("count = %d\n",count);
    return 0;
}
