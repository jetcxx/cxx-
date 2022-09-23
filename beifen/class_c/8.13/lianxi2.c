#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>
//定义无名信号灯
sem_t sem1;
sem_t sem2;
sem_t sem3;
void* myfun1(void *arg)
{
    while(1)
    {
        sem_wait(&sem1);
        printf("B\n");
        sem_post(&sem2);
    }
}
void* myfun2(void *arg)
{
    while(1)
    {
        sem_wait(&sem2);
        printf("C\n");
        sem_post(&sem3);
    }
}
int main(int argc, char const *argv[])
{
    sem_init(&sem1,0,1);
    sem_init(&sem2,0,0);
    sem_init(&sem3,0,0);
    pthread_t tid = 0;
    pthread_t tid1 = 0;
    if(0 != pthread_create(&tid,NULL,myfun1,NULL))
    {
        perror("pthread_create");
    }
    if(0 != pthread_create(&tid,NULL,myfun2,NULL))
    {
        perror("pthread_create1");
    }
    while(1)
    {
        sleep(1);
        sem_wait(&sem3);
        printf("A\n");
        sem_post(&sem1);
    }
    return 0;
}
