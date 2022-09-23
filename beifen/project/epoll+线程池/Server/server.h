#ifndef SERVER_H_
#define SERVER_H_
#include "../proto.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/epoll.h>
#include <sqlite3.h>
//epoll相关
#define ERRLOG(errmsg) do{\
                            perror(errmsg);\
                            printf("%s - %s - %d\n", __FILE__, __func__, __LINE__);\
                            exit(1);\
                            }while(0)



//在线用户列表
typedef struct Online_user_list
{
    char name[20];
    int fd;
    struct Online_user_list *next;
}Online_user_list;



//线程池工作函数传参
typedef struct Myarg
{
    Msg msg;
    int fd;
}Myarg;

//线程池相关
struct job{
    void*(*func)(void *arg);
    void *arg;  //给回调函数传参使用
    struct job * next;
};
struct pthreadpool
{
    int m_threadNum;  //已开启的线程的数量
    pthread_t *m_pthreadIDs;  //保存线程池中线程的ID

    struct job *head;  //任务队列的头
    struct job *rear;  //任务队列的尾

    int m_QueueMaxNum;  //任务队列的最大数
    int m_QueueCurNum; //目前任务队列的任务数

    pthread_mutex_t mutex;

    pthread_cond_t m_QueueEmpty; //任务队列为空的条件
    pthread_cond_t m_QueueNotEmpty; //任务队列为空的条件
    pthread_cond_t m_QueueNotFull; //任务队列为空的条件

};



//函数声明
void *ThreadRun(void *arg);
struct pthreadpool *InitPthreadPool(int ThreadNum, int QueueMaxNum);
void ThreadAddJob(struct pthreadpool *pool, void *(*func)(void *arg), void *arg);
void ThreadDestroy(struct pthreadpool *pool);
void *work(void *arg);
void Create_Sqlite();
int Save_user(Msg mymsg, int client_socket);
int Find_user(Msg mymsg, int client_socket);
int socket_init();
int mypoll(int sockfd);
void Creat_head();
int add_user(Msg mymsg, int client_socket);
int add_user(Msg mymsg, int client_socket);
int find_user(char *name);


#endif