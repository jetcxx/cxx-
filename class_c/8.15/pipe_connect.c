#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int fd[2];
    int fd1[2];
    if(-1 == pipe(fd))
    {
        perror("pipe");
        return -1;
    }
    if(-1 == pipe(fd1))
    {
        perror("pipe");
        return -1;
    }
    pid_t pid = fork();
    if(-1 == pid)
    {
        perror("fork");
        return -1;
    }
    else if(pid == 0)
    {
        close(fd1[0]);
        close(fd[1]);
        while(1)
        {
            char buf[123] = {0};
            read(fd[0],buf,sizeof(buf));
            if(strcmp(buf,"quit") == 0)
            {
                printf("通话结束");
                exit(0);
            }
            printf("父进程说:%s\n",buf);
            printf("请子进程输入消息:\n");
            char buf1[123] = {0};
            fgets(buf1,123,stdin);
            buf1[strlen(buf1)-1] = '\0';
            write(fd1[1],buf1,sizeof(buf1));
        }
    }
    else if(pid > 0)
    {
        close(fd1[1]);
        close(fd[0]);
        while(1)
        {
            printf("请父进程输入:\n");
            char buf[123] = {0};
            fgets(buf,123,stdin);
            buf[strlen(buf)-1] = '\0';
            write(fd[1],buf,sizeof(buf));
            if(strcmp(buf,"quit") == 0)
            {
                printf("通话结束");
                wait(NULL);
                exit(0);
            }
            char buf1[123] = {0};
            read(fd1[0],buf1,sizeof(buf1));
            printf("接收到子进程发送的数据:%s\n",buf1);
        }
    }


    return 0;
}
