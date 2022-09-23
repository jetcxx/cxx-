#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf
{
    long mytype;
    char mtext[1024];
};
struct msgbuf mybuf;
int main(int argc, char const *argv[])
{
    key_t mykey = ftok("/home/cxx/桌面/day/8.15",'a');
    if(mykey == -1)
    {
        printf("生成key值失败\n");
        return -1;
    }

    int MsgId = 0;
    MsgId = msgget(mykey,IPC_CREAT|0664);
    if(-1 == MsgId)
    {
        perror("msgget");
        return -1;
    }
    printf("创建消息队列成功\n");
    while(1)
    {
        fgets(mybuf.mtext,1024,stdin);
        mybuf.mytype = 1;
        mybuf.mtext[strlen(mybuf.mtext)-1] = '\0';
        if(-1 == msgsnd(MsgId,&mybuf,strlen(mybuf.mtext),0))
        {
            perror("msgsnd");
            return -1;
        }
    }
    return 0;
}

