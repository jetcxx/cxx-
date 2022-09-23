#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    //生成一个共享内存使用的key值
    key_t mykey = ftok("/home/jsetc/",'a');
    if(-1 == mykey)
    {
        perror("生成键值失败\n");
        return -1;
    }
    //创建共享内存
    int shmid = shmget(mykey,4096,IPC_CREAT|0664);
    if(-1 == shmid)
    {
        perror("shmid");
        return -1;
    }
    printf("创建共享内存成功\n");
    //地址映射
    char *buf = (char *)shmat(shmid,NULL,0);
    if((char *)-1 == buf)
    {
        perror("shmat");
        return -1;
    }
    //开始操作共享内存
    while(1)
    {
        printf("buf = %s\n",buf);
        sleep(1);
    }
    return 0;
}