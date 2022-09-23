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
#include <stdbool.h>
#include <signal.h>
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
};
struct MSG_DATA msg_data;

struct COMMAND
{
    char CMD[100];
    char buf[100];
};
struct COMMAND CMD;





int setnonblockint(int sockfd) 
{
    fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0) | O_NONBLOCK);
    return 0;
}

void addfd(int epollfd, int fd, bool enable_et) 
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN;
    if (enable_et) 
    {
        ev.events = EPOLLIN | EPOLLET;
    }
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    setnonblockint(fd);
    printf("fd added to epoll!\n\n");
}

void ClientMainMenu();

int enroll();
int Login();
void Mass();
void SendOffline(char *username);
void ClientMenu1(char *username);
void ClientMainMenu1(char *username);
void Privatechat();
void *recvbuf();
int Verifypassword(char *username);
void *command();
int test();
