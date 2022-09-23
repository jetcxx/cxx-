#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int Ticket = 100;
pthread_mutex_t mutex;
void delay()
{
    int x = 10000,y;
    while(x--)
    {
        y = 5000;
        while(y--);
    }
}
void * SaleTicket(void *arg)
{
    int cur_ticket;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        cur_ticket = Ticket;
        if(cur_ticket <=0)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        printf("%ld get %d-th ticket!\n",pthread_self(),cur_ticket);
        cur_ticket--;
        Ticket = cur_ticket;
        pthread_mutex_unlock(&mutex);
        delay();
    }
}
int main(int argc, char const *argv[])
{
    int i,ret;
    pthread_t tid[5] = {0};
    pthread_mutex_init(&mutex,NULL);  //动态初始化一把锁
    for(i = 0; i < 5;i++)
    {
        ret = pthread_create(&tid[i],NULL,SaleTicket,NULL);
        if(ret != 0)
        {
            perror("create");
            return -1;
        }
    }
    for(i = 0; i < 5;i++)
    {
        void *status;
        pthread_join(tid[i],&status); 
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
