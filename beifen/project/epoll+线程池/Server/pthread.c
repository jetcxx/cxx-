#include "server.h"
extern Online_user_list *head;
extern sqlite3* datebase;
extern void Create_Sqlite();
extern int Save_user(Msg mymsg, int client_socket);
void *ThreadRun(void *arg)
{
    struct pthreadpool *pool = (struct pthreadpool *)arg;
    struct job *pjob = NULL;
    while (1)
    {
        pthread_mutex_lock(&pool->mutex);
        if (pool->m_QueueCurNum == 0)
        {
            printf("当前任务队列为空，线程%ld阻塞等待任务到来!\n", pthread_self());
            pthread_cond_wait(&pool->m_QueueNotEmpty, &pool->mutex);
        }
        pjob = pool->head;
        pool->m_QueueCurNum--;
        if (pool->m_QueueCurNum != pool->m_QueueMaxNum)
        {
            pthread_cond_signal(&pool->m_QueueNotFull); //每次线程取出一个任务之后，都要唤醒线程去添加任务
        }
        if (pool->m_QueueCurNum == 0)
        {
            pool->head = pool->rear = NULL;
            pthread_cond_broadcast(&pool->m_QueueEmpty); //当通知任务队列添加任务无果后，发送条件变量，通知其销毁线程
        }
        else
        {
            pool->head = pool->head->next;
        }
        pthread_mutex_unlock(&pool->mutex);
        pjob->func(pjob->arg);
        free(pjob);
        pjob = NULL;
    }
}
struct pthreadpool *InitPthreadPool(int ThreadNum, int QueueMaxNum)
{
    struct pthreadpool *pool = (struct pthreadpool *)malloc(sizeof(struct pthreadpool));
    pool->m_QueueCurNum = 0;
    pool->m_QueueMaxNum = QueueMaxNum;
    pool->head = NULL;
    pool->rear = NULL;
    pool->m_threadNum = ThreadNum;
    pool->m_pthreadIDs = (pthread_t *)malloc(sizeof(pthread_t) * ThreadNum);
    pthread_mutex_init(&pool->mutex, NULL);
    pthread_cond_init(&pool->m_QueueEmpty, NULL);
    pthread_cond_init(&pool->m_QueueNotEmpty, NULL);
    pthread_cond_init(&pool->m_QueueNotFull, NULL);
    for (int i = 0; i < ThreadNum; i++)
    {
        pthread_create(&pool->m_pthreadIDs[i], NULL, ThreadRun, pool);
    }
    return pool;
}
void ThreadAddJob(struct pthreadpool *pool, void *(*func)(void *arg), void *arg)
{
    pthread_mutex_lock(&pool->mutex);
    if (pool->m_QueueCurNum == pool->m_QueueMaxNum)
    {
        printf("任务队列已满，挂起等待线程执行完毕。。。\n");
        pthread_cond_wait(&pool->m_QueueNotFull, &pool->mutex);
    }
    struct job *pjob = (struct job *)malloc(sizeof(struct job));
    pjob->func = func;
    pjob->arg = arg;
    // pjob->func(pjob->arg);
    pjob->next = NULL;
    if (pool->head == NULL)
    {
        pool->head = pool->rear = pjob;
        pthread_cond_broadcast(&pool->m_QueueNotEmpty); //添加任务后，唤醒任意一个线程开始执行任务
    }
    else
    {
        pool->rear->next = pjob;
        pool->rear = pjob;
    }
    pool->m_QueueCurNum++;
    pthread_mutex_unlock(&pool->mutex);
}
void ThreadDestroy(struct pthreadpool *pool)
{
    pthread_mutex_lock(&pool->mutex);
    while (pool->m_QueueCurNum != 0)
    {
        printf("阻塞等待销毁线程。。。\n");
        pthread_cond_wait(&pool->m_QueueEmpty, &pool->mutex);
    }
    printf("任务结束，线程%ld被销毁\n", pthread_self());
    pthread_mutex_unlock(&pool->mutex);
    pthread_cond_broadcast(&pool->m_QueueNotEmpty);
    pthread_cond_broadcast(&pool->m_QueueNotFull);
    int i;
    for (i = 0; i < pool->m_threadNum; i++)
    {
        pthread_join(pool->m_pthreadIDs[i], NULL);
    }
    pthread_mutex_destroy(&pool->mutex);
    pthread_cond_destroy(&pool->m_QueueEmpty);
    pthread_cond_destroy(&pool->m_QueueNotEmpty);
    pthread_cond_destroy(&pool->m_QueueNotFull);
    free(pool->m_pthreadIDs);
    struct job *tmp;
    while (pool->head != NULL)
    {
        tmp = pool->head;
        pool->head = pool->head->next;
        free(tmp);
    }
    free(pool);
}

//线程池工作函数
void *work(void *arg)
{   
    printf("this is work function\n");
    Myarg workarg = *(Myarg *)arg;
    Msg mymsg;
    memset(&mymsg, 0, sizeof(mymsg));
    printf("%s\n", workarg.msg.sourceName);
    switch (workarg.msg.cmd)
    {
    case REG:
        printf("client reg name: %s  passwd %s\n", workarg.msg.sourceName, workarg.msg.buffer);
            if (Save_user(workarg.msg, workarg.fd))
            {
                printf("REG ERROR: Failed to save user\n");
                break;
            }
            memset(&mymsg, 0, sizeof(Msg));
            mymsg.cmd = REG_OK;
            write(workarg.fd, &mymsg, sizeof(Msg));
            break;
        case LOG:
            printf("client log name: %s  passwd %s\n", workarg.msg.sourceName, workarg.msg.buffer);
            if (find_user_list(workarg.msg.sourceName) == 0)
            {
                if (Find_user(workarg.msg, workarg.fd))
                {
                    printf("LOG ERROR: Failed to save user in Online user list\n");
                    break;
                }
                //在线用户列表
                add_user(workarg.msg, workarg.fd);
                break;
            }
            memset(&mymsg, 0, sizeof(Msg));
            mymsg.cmd = LOG_ONLINE;
            write(workarg.fd, &mymsg, sizeof(Msg));
            break;
        case CHATONE:
            printf("%s  chat one with %s\n", workarg.msg.sourceName,workarg.msg.destinationName);
            int find_ret = find_user(workarg.msg.destinationName);
            if (find_ret == 0)
            {
                printf("查无此人......\n");
                memset(&mymsg, 0, sizeof(Msg));
                mymsg.cmd = NOBODY;
                write(workarg.fd, &mymsg, sizeof(Msg));
                break;
            }
            write(find_ret, &workarg.msg,sizeof(Msg));
            break;
        case CHATALL:
            printf("client chatall name: %s \n", workarg.msg.sourceName);
            // int find_ret = find_user(mymsg.sourceName);
            Online_user_list *tmp = head->next;
            while (tmp != NULL)
            {
                if (strcmp(tmp->name, workarg.msg.sourceName) != 0)
                {
                    write(tmp->fd, &workarg.msg, sizeof(mymsg));
                }
                tmp = tmp->next;
            }
            break;
        default:
            break;
    }
}
