#ifndef __PROTO_H
#define _PROTO_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/errno.h>

#define PORT 9999

#define REG 1999       //注册
#define LOG 2000       //登录
#define REG_OK 2001    //注册成功
#define LOG_OK 2002    //登录成功
#define LOG_ERROR 2003 //登录失败
#define LOG_ONLINE 2005  //用户已经登陆
#define REG_ERROR_AGAIN 2004 //注册失败
#define LOOK_LIST  2006  //查看在线用户
#define ROOT_LOG_OK    //管理员登录成功
#define ROOT_LOG_ERROR //管理员登录失败
#define BUFFER_SIZE 1024   //定义缓冲区大小

#define CHATALL  9999   //群聊
#define CHATONE  9998   //私聊

#define NOBODY   6000   //查无此人

//定义通信消息格式
typedef struct Msg
{
   int cmd;    //消息命令控制字
   char sourceName[13];  //消息的发送者   
   char buffer[BUFFER_SIZE];     //消息内容
   char destinationName[13];  //消息的接收者
}Msg;



#endif

