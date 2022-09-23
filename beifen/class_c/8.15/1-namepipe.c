#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, const char *argv[])
{
    //创建有名管道,不具备区检测文件存在则打开文件的功能
    if(-1 == mkfifo("./myfifo",0664))
    {
        if(errno == EEXIST)
        {
            printf("文件已经存在，直接打开\n");
        }
        else
        {
            perror("mkfifo");
            return -1;
        }
    }
    if(-1 == mkfifo("./myfifo1",0664))
    {
        if(errno == EEXIST)
        {
            printf("文件已经存在，直接打开\n");
        }
        else
        {
            perror("mkfifo");
            return -1;
        }
    }
    //打开有名管道
    //myfifo作为读端，myfifo1作为写段
    int fd = open("./myfifo",O_RDONLY);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }
    printf("打开文件成功");
    int fd1 = open("./myfifo1",O_WRONLY);
    if(-1 == fd1)
    {
        perror("open1");
        return -1;
    }
    printf("打开管道文件成功\n");
    while(1)
    {
        char buf[123] ={0};
        read(fd,buf,sizeof(buf));
        if(strcmp(buf,"quit") == 0)
        {
            printf("通信结束\n");
            exit(0);
        }
        printf("buf = %s\n",buf);
        //开始回复消息
        printf("请输入：");
        char buf1[123] ={0};
        fgets(buf1,123,stdin);
        buf1[strlen(buf1)-1] = '\0';
        write(fd1,buf1,strlen(buf1));
        if(strcmp(buf1,"quit") == 0)
        {
            printf("通信结束\n");
            exit(0);
        }
    }
    return 0;
}