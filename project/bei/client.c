#include "client.h"

int scan=1;
int cmd =0;
int rcv = 1;

int sockfd;
struct sockaddr_in serveraddr;
socklen_t addrlen = sizeof(serveraddr);
char buf[N] = {0};
char filename[N] = {0};
//int fd;
sqlite3 *usrdb;


void ClientMainMenu()
{
    printf("----------------------------------------------------\n");
    printf("-------------a.注册\t\tb.登录-----------------\n");
    printf("-------------c.退出-----------------\n");
    printf("-----------------------------------------------------\n");
    printf("请输入操作指令:\n");
}

int enroll()
{
    
    char username[10] = {0};
    char passwd1[100] = {0};
    char passwd2[100] = {0};
    printf("请输入用户名:\n");
    scanf("%s",username);
AA:
    printf("请输入密码:\n");
    scanf("%s",passwd1);
    printf("请再输入一次密码:\n");
    scanf("%s",passwd2);
    if(strcmp(passwd2,passwd1) != 0)
    {
        printf("两次输入密码不一致，返回重新确认密码\n");
        goto AA;
    }
    else
    {
        memset(msg_data.cmd,0,sizeof(msg_data.cmd));
        sprintf(msg_data.cmd,"enroll");
        sprintf(msg_data.username,"%s",username);
        sprintf(msg_data.passwd,"%s",passwd1);
        
        send(sockfd,&msg_data,sizeof(msg_data),0);

    }
}

int Login()
{
    
    char username[10] = {0};
    char passwd[100] = {0};
    printf("请输入用户名:\n");
    scanf("%s",username);
    printf("0000000\n");
    memset(msg_data.cmd,0,sizeof(msg_data.cmd));
    sprintf(msg_data.cmd,"login");
    sprintf(msg_data.username,"%s",username);
    send(sockfd,&msg_data,sizeof(msg_data),0);

    
}

int Verifypassword(char *username)
{
    cmd = 0;
    char passwd[10] = {0};
    char username1[10] = {0};
    strcpy(username1,username);
    printf("输入密码:\n");
    //fflush(stdin);
    scanf("%s",passwd);
    printf("12345678\n");
    }
    printf("22222\n");
    memset(msg_data.cmd,0,sizeof(msg_data.cmd));
    sprintf(msg_data.cmd,"VerifyPassword");
    printf("11111\n");
    printf("cmd = %s\n",msg_data.cmd);
    strcpy(msg_data.passwd,passwd);
    //sprintf(msg_data.passwd,"%s",passwd);
    strcpy(msg_data.username,username1);
    send(sockfd,&msg_data,sizeof(msg_data),0);
    strcpy(CMD.CMD,"0");
    return 0;
}



void SendOffline(char *username)
{
    memset(&msg_data,0,sizeof(msg_data));
    strcpy(msg_data.cmd,"offline");
    strcpy(msg_data.username,username);
    send(sockfd,&msg_data,sizeof(msg_data),0);
}







void ClientMenu1(char *username)
{
    char choice;
    printf("欢迎登录,%s\n",username);
    printf("*\t\ta.群发\t\t          b.私聊       \t\t*\n");
    printf("*\t\tc.查看当前在线用户\t\td.查看聊天记录\t\t*\n");
    printf("*\t\t           e.返回主菜单          \t\t*\n");
    printf("请输入操作指令:\n");
    
    while(1)
    {
        getchar();
        scanf("%c",&choice);
        
        switch (choice)
        {
        case 'a':
            Mass();
            break;
        case 'b':
            Privatechat();
            break;
        
        case 'e':
            ClientMainMenu1(username);
            break;
        default:
            printf("无效输入\n");
            break;
        }
        //getchar();
    }
}

void ClientMainMenu1(char *username)
{
    printf("----------------------------------------------------\n");
    printf("-------------a.注册\t\tb.登录-----------------\n");
    printf("-------------c.退出-----------------\n");
    printf("-----------------------------------------------------\n");
    printf("请输入操作指令:\n");
    char choice;
    while(1)
    {
        printf("**************\n");
        scanf("%c",&choice);
        printf("&&&&&&&&\n");
        switch (choice)
        {
        case 'a':
            enroll();
            break;
        case 'b':
            Login();
            break;
        case 'c':
            SendOffline(username);
            exit(1);
            break;
        default:
            break;
        }
    }
}


void Mass()
{
    printf("1111\n");
    char buf[100] ={0};
    //memset(&msg_data,0,sizeof(msg_data));
        printf("输入你想说的话:\n");
        scanf("%s",buf);
        

        strcpy(msg_data.buff,buf);
        printf("msg.buf = %s\n",msg_data.buff);

        strcpy(msg_data.cmd,"mass");
        //printf("%s\n",msg_data.buff);
        //write(sockfd,msg_data.buff,sizeof(msg_data.buff));
        //write(sockfd,&msg_data,sizeof(struct MSG_DATA));
        int sendsize = send(sockfd, &msg_data, sizeof(msg_data),0);
        //printf("sendsize = %d\n",sendsize);
        while(1)
        {
            if(recv(sockfd,&msg_data,sizeof(msg_data),0) > 0)
            {
                break;
            }
            break;
        }

}

void Privatechat()
{
    char buf[100] = {0};
    char username[10] = {0};
    printf("你想对谁说\n");
    scanf("%s",username);
    printf("说什么:\n");
    scanf("%s",buf);
    memset(&msg_data,0,sizeof(msg_data));
    strcpy(msg_data.cmd,"Privatechat");
    strcpy(msg_data.username,username);
    strcpy(msg_data.buff,buf);
    send(sockfd,&msg_data,sizeof(msg_data),0);
    
}

int test()
{
    printf("test success!\n");
    return 0;
}


//接收服务器发来的数据
void *recvbuf()
{   
    int ret;
    while(1)
    {
        if(rcv)
        {
        if(ret=(recv(sockfd,&msg_data,sizeof(msg_data),0) )== -1)
        {
            ERRLOG("recv");
        }
        
        // else if(ret==0)
        // {
        //    printf("客户机下线\n");
        // }
        if(strcmp(msg_data.cmd,"passenroll") == 0)
        {
            printf("注册成功，返回主菜单....\n");
            ClientMainMenu();
        }
        else if(strcmp(msg_data.cmd,"loginusrnameagain") == 0)
        {
            printf("用户名不存在，重新登录\n");
            Login();
        }
        else if(strcmp(msg_data.cmd,"loginusrnamepass") == 0)
        {
            //test();
            //char username[10] = {0};
            //printf("7777777\n");
            strcpy(CMD.buf,msg_data.username);
            strcpy(CMD.CMD,"100");
            cmd = 1;
            
            
            rcv = 0;
            
            
            //Verifypassword(username);

        }
        else if(strcmp(msg_data.cmd,"loginpasswdagain") == 0)
        {
            printf("密码错误,重新登录\n");
            Login();
        }
        else if(strcmp(msg_data.cmd,"loginpasswdpass") == 0)
        {
            char username[10] = {0};
            strcpy(username,msg_data.username);
            ClientMenu1(username);
        }
    }
    }
    printf("接收到%s\n",msg_data.buff);
}

void *command()
{
    
    
    while(1)
    {       
        if(cmd){printf("7777777777\n");
        if(strcmp(CMD.CMD,"100") == 0)
        {
            
            printf("cmd yes\n");
            Verifypassword(CMD.buf);
            
            
        }
    }}
    
}




int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }
    
    //第一步：创建套接字
    if((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    {
        ERRLOG("socket error");
    }
    //第二步：填充服务器网络信息结构体
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    struct epoll_event ev,events[2000] = {0};

    //第三步：给服务器发送客户端的连接请求
    if(connect(sockfd, (struct sockaddr *)&serveraddr, addrlen) == -1)
    {
        ERRLOG("connect error");
    }
    else
    {
        printf("connect success!\n");
    }

    pthread_t tid = 0;
    if(pthread_create(&tid,NULL,recvbuf,NULL) != 0)
    {
        printf("线程创建已失败\n");
        return -1;
    }

    pthread_t tid1 = 1;
    if(pthread_create(&tid1,NULL,command,NULL) != 0)
    {
        printf("线程创建已失败\n");
        return -1;
    }

    printf("**************************************************\n");
    printf("**********************欢迎使用*********************\n");
    printf("**************************************************\n");
    ClientMainMenu();
    char choice;
    while(1)
    {   
        if(scan)
        {
            scanf("%c",&choice);
        }
        scan=0;
        switch (choice)
        {
        case 'a':
            enroll();
            break;
        case 'b':
            Login();
            break;
        case 'c':
            exit(1);
            break;
        default:
            break;
        }
        scan=1;
    }

    
    return 0;
}