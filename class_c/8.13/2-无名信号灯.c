#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int count = 0;
sem_t sem1;
sem_t sem2;

void* Myfun(void *arg)
{
    while(1)
    {
        sem_wait(&sem2);
        count++;
        sem_post(&sem1);
    }
}

int main(int argc, char const *argv[])
{
    sem_init(&sem1,0,0);
    sem_init(&sem2,0,1);
    pthread_t tid = 0;
    if(0 != pthread_create(&tid,NULL,Myfun,NULL))
    {
        perror("pthread_creat");
        return -1;
    }
    while(1)
    {
        sem_wait(&sem1);
        printf("count = %d\n",count);
        sem_post(&sem2);
    }
    return 0;
}
