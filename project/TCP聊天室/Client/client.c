#include "client.h"

int scan=1;
int cmd =0;
int rcv = 1;
int clientmenu = 1;
int clientmainmenu = 1;
int adminmenu = 1;
int silence = 1;
int enrollpass = 1;
int wait = 0;


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
    
}

int enroll()
{
    
    char username[10] = {0};
    char passwd1[100] = {0};
    char passwd2[100] = {0};
    printf("请输入用户名:\n");
    getchar();
    scanf("%s",username);
    strcpy(msg_data.username,username);
    strcpy(msg_data.cmd,"VerifyUsernameExists");
    send(sockfd,&msg_data,sizeof(msg_data),0);

    

}

int VerifyUsername(char *username)
{
    char username1[10] = {0};
    char passwd1[100] = {0};
    char passwd2[100] = {0};
    strcpy(username1,username);
    if(enrollpass == 0)
    {
        printf("此用户名已存在,重新选一个吧\n");
        enroll();
    }
    if(enrollpass)
    {
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
            strcpy(msg_data.username,username1);
            strcpy(msg_data.passwd,passwd1);     
            send(sockfd,&msg_data,sizeof(msg_data),0);
        }
    }
}



void Login()
{
    
    char username[10] = {0};
    char passwd[100] = {0};
    printf("请输入用户名:\n");
    fflush(stdin);
    getchar();
    scanf("%s",username);
    strcpy(msg_data.username,username);
    strcpy(msg_data.cmd,"VerifyUserisloggedin");
    send(sockfd,&msg_data,sizeof(msg_data),0);


    //printf("0000000\n");
    
    return;
}

void Loginpass(char *username)
{
    char username1[10] = {0};
    strcpy(username1,username);
    strcpy(msg_data.cmd,"login");
    strcpy(msg_data.username,username1);
    send(sockfd,&msg_data,sizeof(msg_data),0);
    rcv =1;
    return;
}

int Verifypassword(char *username)
{
    char passwd[10] = {0};
    char username1[10] = {0};
    strcpy(username1,username);
    printf("输入密码:\n");
    fflush(stdin);
    scanf("%s",passwd);
    //printf("12345678\n");
    //printf("22222\n");
    memset(msg_data.cmd,0,sizeof(msg_data.cmd));
    sprintf(msg_data.cmd,"VerifyPassword");
    //printf("11111\n");
    //printf("cmd = %s\n",msg_data.cmd);
    strcpy(msg_data.passwd,passwd);
    //sprintf(msg_data.passwd,"%s",passwd);
    strcpy(msg_data.username,username1);
    //strcpy(CMD.CMD,"0");
    send(sockfd,&msg_data,sizeof(msg_data),0);
    
    
    return 0;
}



void SendOffline(char *username)
{
    char username1[10] = {0};
    strcpy(username1,username);
    memset(&msg_data,0,sizeof(msg_data));
    strcpy(msg_data.cmd,"offline");
    strcpy(msg_data.username,username1);
    send(sockfd,&msg_data,sizeof(msg_data),0);
}






//用户登录后的菜单
void ClientMenu(char *username)
{
CC:
    cmd = 0;
    strcpy(CMD.CMD,"0");
    char choice;
    char username1[10] = {0};
    strcpy(username1,username);
    printf("欢迎登录,%s\n",username);
    printf("*\t\ta.群发\t\t    b.私聊    \t\t*\n");
    printf("*\t\tc.查看当前在线用户\t\td.查看聊天记录\t\t*\n");
    printf("*\t\te.返回主菜单\t\tf.注销此账号*\n");
    printf("*\t\t\tg.下载文件\t\t\t\n");
    printf("请输入操作指令:\n");
    
    if(clientmenu)
    {
    while(1)
    {
        
        getchar();
        scanf("%c",&choice);
        
        
        switch (choice)
        {
        case 'a':
            if(silence)
            {
                memset(&choice,0,sizeof(choice));
                Mass(username1);
                goto CC;
            }
            else if(silence == 0)
            {
                printf("你已被禁言\n");
            }
            break;
        case 'b':
            if(silence)
            {
                memset(&choice,0,sizeof(choice));
                Privatechat(username1);
                goto CC;
            }
            else if(silence == 0)
            {
                printf("你已被禁言\n");
            }
            break;
        case 'c':
            memset(&choice,0,sizeof(choice));
            fflush(stdout);
            ViewOnlineUser();
            goto CC;
            break;
        case 'd':
            memset(&choice,0,sizeof(choice));
            fflush(stdout);
            ViewChathistory();
            goto CC;
            break;
        case 'e':
            ClientMainMenu1(username1);
            break;
        case 'f':
            Logout(username1);
            break;
        case 'g':
            DownloadFile();
            break;

        default:
            clientmenu = 0;
            printf("无效输入\n");
            break;
        }
    }
    
        //getchar();
    }
    return;
}

int DownloadFile()
{
    char filename[10] = {0};
    printf("输入你想下载的文件名:\n");
    getchar();
    scanf("%s",filename);
    strcpy(msg_data.buff,filename);
    strcpy(msg_data.cmd,"downloadfile");
    send(sockfd,&msg_data,sizeof(msg_data),0);
}

void Logout(char *username)
{
    //注销分几步？先退出，再删库！
    char username1[10] = {0};
    strcpy(username1,username);
    SendOffline(username1);
    memset(&msg_data,0,sizeof(msg_data));
    strcpy(msg_data.cmd,"logout");
    strcpy(msg_data.username,username1);
    send(sockfd,&msg_data,sizeof(msg_data),0);
    
}


void ViewChathistory()
{
    strcpy(msg_data.cmd,"ViewChathistory");
    send(sockfd,&msg_data,sizeof(msg_data),0);
}

void ViewOnlineUser()
{
    strcpy(msg_data.cmd,"ViewOnlineUser");
    send(sockfd,&msg_data,sizeof(msg_data),0);
}


//有scanf，还要改
void ClientMainMenu1(char *username)
{
    printf("----------------------------------------------------\n");
    printf("-------------a.注册\t\tb.登录-----------------\n");
    printf("-------------c.退出---------------------------\n");
    printf("-----------------------------------------------------\n");
    printf("请输入操作指令:\n");
    char choice;
    while(1)
    {
        if(clientmainmenu)
        {
        //printf("**************\n");
        getchar();
        scanf("%c",&choice);
        //printf("&&&&&&&&\n");
        }
        clientmainmenu = 0;
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


void Mass(char *sender)
{
    //printf("1111\n");
    char sender1[10] = {0};
    char buf[100] ={0};
    //memset(&msg_data,0,sizeof(msg_data));
    printf("输入你想说的话:\n");
    getchar();
    scanf("%s",buf);
    

    strcpy(msg_data.buff,buf);
    strcpy(sender1,sender);
    strcpy(msg_data.sender,sender1);
    //printf("msg.buf = %s\n",msg_data.buff);

    strcpy(msg_data.cmd,"mass");
    //printf("%s\n",msg_data.buff);
    //write(sockfd,msg_data.buff,sizeof(msg_data.buff));
    //write(sockfd,&msg_data,sizeof(struct MSG_DATA));
    send(sockfd, &msg_data, sizeof(msg_data),0);
    return;
}

void Privatechat(char *username)
{
    char sender[10] = {0};
    strcpy(sender,username);
    printf("sender = %s\n",sender);
    char buf[100] = {0};
    char username1[10] = {0};
    printf("你想对谁说\n");
    getchar();
    scanf("%s",username1);
    printf("说什么:\n");
    getchar();
    scanf("%s",buf);
    //memset(&msg_data,0,sizeof(msg_data));
    strcpy(msg_data.cmd,"Privatechat");
    strcpy(msg_data.username,username1);
    strcpy(msg_data.buff,buf);
    strcpy(msg_data.sender,sender);
    send(sockfd,&msg_data,sizeof(msg_data),0);
    return;
}


int AdminMenu(char *username)
{
    char choice;
    char username1[10] = {0};
    strcpy(username1,username);
    cmd = 0;
    strcpy(CMD.CMD,"0");
DD:
    printf("---------a.私发\t\tb.群发--------------\n");
    printf("---------c.查看在线用户\t\td.查看聊天记录---------\n");
    printf("---------e.踢人\t\tf.禁言-----------\n");
    printf("---------g.解禁用户\t\th.退出管理员账户-------------\n");
    printf("请输入管理员操作:\n");
    getchar();
    scanf("%c",&choice);
    if(adminmenu)
    {
        
        switch (choice)
        {
        case 'a':
            memset(&choice,0,sizeof(choice));
            Privatechat(username1);
            goto DD;
            break;
        case 'b':
            memset(&choice,0,sizeof(choice));
            Mass(username1);
            goto DD;
            break;
        case 'c':
            memset(&choice,0,sizeof(choice));
            ViewOnlineUser();
            goto DD;
            break;
        case 'd':
            memset(&choice,0,sizeof(choice));
            ViewChathistory();
            goto DD;
            break;

        case 'e':
            memset(&choice,0,sizeof(choice));
            Kick();
            goto DD;
            break;
        case 'f':
            memset(&choice,0,sizeof(choice));
            Silence();
            goto DD;
            break;

        case 'g':
            memset(&choice,0,sizeof(choice));
            Lifting();

            goto DD;
            break;

        case 'h':
            ClientMainMenu1(username1);
            break;
        
        default:
            printf("错误输入\n");
            adminmenu = 0;
            break;
        }
    }
}

int Kick()
{
    char username[10] = {0};
    printf("输入要踢出的用户:\n");
    getchar();
    scanf("%s",username);
    strcpy(msg_data.cmd,"kick");
    strcpy(msg_data.username,username);
    send(sockfd,&msg_data,sizeof(msg_data),0);
}

int Silence()
{
    char username[10] ={0};
    printf("输入要禁言的用户:\n");
    getchar();
    scanf("%s",username);
    strcpy(msg_data.cmd,"silence");
    strcpy(msg_data.username,username);
    send(sockfd,&msg_data,sizeof(msg_data),0);
}

int Lifting()
{
    char username[10] ={0};
    printf("输入要解除禁言的用户:\n");
    getchar();
    scanf("%s",username);
    strcpy(msg_data.cmd,"Lifting");
    strcpy(msg_data.username,username);
    send(sockfd,&msg_data,sizeof(msg_data),0);
}



int test()
{
    printf("test success!\n");
    return 0;
}


//接收服务器发来的数据
//收
void *recvbuf()
{   
    int ret;
    while(1)
    {

       
        if(ret=(recv(sockfd,&msg_data,sizeof(msg_data),0) )== -1)
        {
            ERRLOG("recv");
        }
        //}
        
        // else if(ret==0)
        // {
        //    printf("客户机下线\n");
        // }
        if(strcmp(msg_data.cmd,"passenroll") == 0)
        {
            printf("注册成功，请登录....\n");
            strcpy(CMD.CMD,"100");
            cmd = 1;
            //Login();
        }
        else if(strcmp(msg_data.cmd,"loginusrnameagain") == 0)
        {
            printf("用户名不存在，重新登录\n");
            strcpy(CMD.CMD,"100");
            cmd = 1;
            //Login();
        }
        else if(strcmp(msg_data.cmd,"VerifyUsernameExistsPass") == 0)
        {
            char username[10] = {0};
            memset(&CMD,0,sizeof(CMD));
            strcpy(CMD.buf,msg_data.username);
            //strcpy(username,msg_data.username);
            enrollpass = 1;
            strcpy(CMD.CMD,"200");
            cmd = 1;
            //VerifyUsername(username);           
        }
        else if(strcmp(msg_data.cmd,"VerifyUsernameExistsAgain") == 0)
        {
            char username[10] = {0};
            memset(&CMD,0,sizeof(CMD));
            strcpy(CMD.buf,msg_data.username);
            enrollpass = 0;
            strcpy(CMD.CMD,"200");
            cmd = 1;
            //VerifyUsername(username);
        }

        else if(strcmp(msg_data.cmd,"userisloggedinagain") == 0)
        {
            printf("此用户已登录,不可重复登录\n");
            memset(&CMD,0,sizeof(CMD));
            strcpy(CMD.CMD,"100");
            cmd = 1;
            //Login();
        }

        else if(strcmp(msg_data.cmd,"userisloggedinpass") == 0)
        {
            char username[10] = {0};
            memset(&CMD,0,sizeof(CMD));
            strcpy(CMD.buf,msg_data.username);
            //strcpy(username,msg_data.username);
            printf("登录中，请稍后.....\n");
            //rcv = 0;
            strcpy(CMD.CMD,"300");
            cmd = 1;
            //Loginpass(username);
        }
        

        else if(strcmp(msg_data.cmd,"loginusrnamepass") == 0)
        {
            //test();
            //char username[10] = {0};
            //printf("6666666\n");
            strcpy(CMD.buf,msg_data.username);
            strcpy(CMD.CMD,"400");
            //rcv = 0;
            cmd = 1;
            
            
            
            
            
            //Verifypassword(username);

        }
        else if(strcmp(msg_data.cmd,"loginpasswdagain") == 0)
        {
            printf("密码错误,重新登录\n");
            memset(&CMD,0,sizeof(CMD));
            strcpy(CMD.CMD,"100");
            cmd = 1;
            //Login();
        }
        else if(strcmp(msg_data.cmd,"loginpasswdpass") == 0)
        {
            printf("密码正确,登录\n");
            strcpy(CMD.buf,msg_data.username);
            strcpy(CMD.CMD,"500");
            //char username[10] = {0};          
            cmd = 1;
            //strcpy(username,msg_data.username);
            //ClientMenu(username);
        }

        //有私聊信息发来
        else if(strcmp(msg_data.cmd,"chatone") == 0)
        {
            //printf("$$$$$$$^^^^^^^^^^\n");
            char sender[10] = {0};
            char buf[100] = {0};
            strcpy(sender,msg_data.sender);
            strcpy(buf,msg_data.buff);
            printf("%s发来消息:%s\n",sender,buf);
        }


        else if(strcmp(msg_data.cmd,"chatall") == 0)
        {
            char sender[10] = {0};
            char buf[100] = {0};
            strcpy(sender,msg_data.sender);
            strcpy(buf,msg_data.buff);
            printf("%s向所有人发送消息:%s\n",sender,buf);
        }

        else if (strcmp(msg_data.cmd,"ViewOnlineUser") == 0)
        {
            char buf[100] = {0};
            strcpy(buf,msg_data.buff);
            fflush(stdin);
            printf("%s\n",buf);
        }

        else if(strcmp(msg_data.cmd,"ViewChathistory") == 0)
        {
            char buf[100] = {0};
            strcpy(buf,msg_data.buff);
            getchar();
            printf("聊天记录:%s\n",buf);
        }

        else if(strcmp(msg_data.cmd,"loginadminpasswdpass") == 0)
        {
            
            
            printf("欢迎管理员用户登录！\n");
            memset(&CMD,0,sizeof(CMD));
            strcpy(CMD.buf,msg_data.username);
            strcpy(CMD.CMD,"600");
            cmd = 1;
            
        }

        else if(strcmp(msg_data.cmd,"kicked") == 0)
        {
            SendOffline(msg_data.username);
            printf("你已被管理员踢出聊天室\n");
            exit(1);
        }

        else if(strcmp(msg_data.cmd,"silenced") == 0)
        {
            silence = 0;
        }

        else if(strcmp(msg_data.cmd,"Lifting") == 0)
        {
            silence = 1;
        }

        else if(strcmp(msg_data.cmd,"logoutsuccess") == 0)
        {
            printf("你的账户已注销,欢迎下次使用\n");
            exit(1);
        }
        else if(strcmp(msg_data.cmd,"fileisnotexist") == 0)
        {
            printf("此文件不存在，无法下载\n");
        }
        else if(strcmp(msg_data.cmd,"fileisexist") == 0)
        {
            printf("文件存在,准备下载...\n");
            FILE *fp = fopen(msg_data.buff,"w");
            if(fp == NULL)
            {
                ERRLOG("fopen");
            }
            printf("%s\n",msg_data.passwd);
            fwrite(msg_data.passwd,sizeof(msg_data.passwd),1,fp);

            sleep(1);
            printf("下载成功\n");

        }

        
        
    
    }
    printf("接收到%s\n",msg_data.buff);
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


    pthread_mutex_init(&mutex, NULL);

    
    pthread_t tid = 0;
    if(pthread_create(&tid,NULL,recvbuf,NULL) != 0)
    {
        printf("线程创建已失败\n");
        return -1;
    }

    // pthread_t tid1 = 1;
    // if(pthread_create(&tid1,NULL,command,NULL) != 0)
    // {
    //     printf("线程创建已失败\n");
    //     return -1;
    // }

    printf("**************************************************\n");
    printf("**********************欢迎使用*********************\n");
    printf("**************************************************\n");
    ClientMainMenu();
    char choice;
    while(1)
    {   
        if(scan)
        {
            printf("请输入操作指令:\n");
            scanf("%c",&choice);
        }
        scan=0;
        switch (choice)
        {
        case 'a':
            enroll();
            memset(&choice,0,sizeof(choice));
            break;
        case 'b':
            Login();
            memset(&choice,0,sizeof(choice));
            break;
        case 'c':
            exit(1);
            break;
        default:
            break;
        }
        if(cmd)
        {
            sleep(1);
            //printf("7777777777\n");
            if(strcmp(CMD.CMD,"100") == 0)
            {
                cmd = 0;
                Login();
                // printf("cmd yes\n");
                // Verifypassword(CMD.buf);
            }
            if(strcmp(CMD.CMD,"200") == 0)
            {cmd = 0;
                char username[10] = {0};
                strcpy(username,CMD.buf);
                VerifyUsername(username);
                //printf("用户登录后菜单\n");
                //ClientMenu(CMD.buf);
            }
            if(strcmp(CMD.CMD,"300") == 0)
            {cmd = 0;
                char username[10] = {0};
                strcpy(username,CMD.buf);
                Loginpass(username);
            }
            if(strcmp(CMD.CMD,"400") == 0)
            {cmd = 0;
                Verifypassword(CMD.buf);
            }
            if(strcmp(CMD.CMD,"500") == 0)
            {cmd = 0;
                printf("用户登录后菜单\n");
                ClientMenu(CMD.buf);
            }
            if(strcmp(CMD.CMD,"600") == 0)
            {cmd = 0;
                AdminMenu(CMD.buf);
            }

            //pthread_mutex_unlock(&mutex);
        }
        //scan=1;
    }
    // //发
    // while(1)
    // {       
    //     //sleep(1);
    //         //pthread_mutex_lock(&mutex);
        
    //     //cmd = 0;
    // }

    
    return 0;
}