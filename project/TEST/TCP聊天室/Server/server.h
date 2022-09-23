#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/epoll.h>
#include <sqlite3.h>
#include <pthread.h>

#define N 128
#define ERRLOG(errmsg) do{\
                            perror(errmsg);\
                            printf("%s - %s - %d\n", __FILE__, __func__,__LINE__);\
                            exit(1);\
                            }while(0)
#define BUF_SIZE 0xFFFF

struct MSG_DATA
{
    char cmd[100];
    unsigned char buff[100];  //发送的聊天数据消息
    char username[10];
    char passwd[100];
    char sender[10];
};
struct MSG_DATA msg_data;

typedef struct tpool_work
{
    void*  (*routine)(void*);
    void   *arg;
    struct tpool_work *next;

}tpool_work_t;

typedef struct tpool
{
    int shutdown;
    int max_thr_num;
    pthread_t *thr_id;
    tpool_work_t *queue_head;
    tpool_work_t *queue_tail;
    pthread_mutex_t queue_lock;
    pthread_cond_t queue_ready;
}tpool_t;

int tpool_create(int max_thr_num);

void tpool_destory();

int tpool_add_work(void*(*routine)(void*),void *arg);



struct CLIENT_FD *list_head=NULL;
struct CLIENT_FD *List_CreateHead(struct CLIENT_FD *list_head);



int enroll(char *username,char *passwd);
int VerifyUsername(char *username);
int VerifyPassword(char *passwd);
int Saveonlineuser(char *username,int fd);
int DeleteOnlineUser(char *username);
int Privatechat(char *username,char *buf,char *sender);
int Mass(char *sender,char *buf);
int ViewOnlineUser();
int ViewChathistory();




int setnonblockint(int sockfd);
void addfd(int epollfd, int sockfd, int enable_et);