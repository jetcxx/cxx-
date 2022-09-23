#include "server.h"
Online_user_list *head = NULL; //在线用户列表
sqlite3 *datebase = NULL;
struct pthreadpool *pool;
extern int socket_init();
extern void Creat_head();
extern int mypoll(int);
extern struct pthreadpool *InitPthreadPool(int ThreadNum, int QueueMaxNum);
int main()
{
    int sockfd = socket_init();
    pool = InitPthreadPool(1, 10);
    Creat_head();
    Create_Sqlite(&datebase);
    mypoll(sockfd);
    return 0;
}
