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
    long mtype;
    char mtext[1024];
};
struct msgbuf mybuf;
int main(int argc, const char *argv[])
{
    //创建一个key值
    key_t mykey = ftok("/home/cxx/桌面/day/8.15",'a');
    if(mykey == -1)
    {
        printf("生成key值失败\n");
        return -1;
    }
    //打开或者创建消息队列
    int MsgId = 0;
    MsgId = msgget(mykey,IPC_CREAT|0664);
    if(-1 == MsgId)
    {
        perror("msgget");
        return -1;
    }
    printf("创建消息队列成功\n");
    //开始接受数据
    while(1)
    {
        //接受数据
        if(-1 == msgrcv(MsgId,&mybuf,sizeof(mybuf.mtext),1,0))
        {
            perror("msgrcv");
            return -1;
        }
        printf("buf = %s\n",mybuf.mtext);
    }
    return 0;
}