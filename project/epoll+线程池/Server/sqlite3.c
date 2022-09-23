#include "server.h"
extern sqlite3 *datebase;
void  Create_Sqlite(sqlite3 **db)
{   
    printf("Create_Sqlite() returning\n");
    int ret = sqlite3_open("chat.db", db);
    if (ret != SQLITE_OK)
    {
        printf("数据库打开失败\n");
        return ;
    }
    printf("数据库打开成功\n");
}
int Save_user(Msg mymsg, int client_socket)
{
    char *errmsg = NULL;
    char buf[100] = "create table if not exists user(NAME TEXT,Password TEXT,primary key(NAME))";
    printf("111111111111111\n");
    int ret = sqlite3_exec(datebase, buf, NULL, NULL, &errmsg);
    printf("2222222222222222222222\n");
    if (ret != SQLITE_OK)
    {
        printf("REG 打开表失败\n");
        printf("sqlite3_exec: %s\n", errmsg);
        return -1;
    }
    printf("REG 打开表成功\n");
    //判断表中是否已存在相同账号名
    char **resultp = NULL;
    int nrow, ncolumn;
    char *sql = "select * from user";
    ret = sqlite3_get_table(datebase, sql, &resultp, &nrow, &ncolumn, &errmsg);
    if (ret != SQLITE_OK)
    {
        printf("REG 数据库操作失败\n");
        return -1;
    }
    int i;
    int flag = 0;
    for (i = 0; i < (nrow + 1) * ncolumn; i += 2)
    {
        if (strcmp(resultp[i], mymsg.sourceName) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        Msg temp;
        memset(&temp, 0, sizeof(temp));
        temp.cmd = REG_ERROR_AGAIN;
        write(client_socket, &temp, sizeof(temp));
        return -1;
    }
    //插入数据
    sprintf(buf, "insert into user values('%s', '%s')", mymsg.sourceName, mymsg.buffer);
    ret = sqlite3_exec(datebase, buf, NULL, NULL, &errmsg);
    if (ret != SQLITE_OK)
    {
        printf("REG 插入数据失败\n");
        return -1;
    }
    return 0;
}
int Find_user(Msg mymsg, int client_socket)
{
    char *errmsg = NULL;
    char buf[100] = "create table if not exists user(NAME TEXT,Password TEXT)";
    int ret = sqlite3_exec(datebase, buf, NULL, NULL, &errmsg);
    if (ret != SQLITE_OK)
    {
        printf("LOG 打开表失败\n");
        printf("sqlite3_exec: %s\n", errmsg);
        return -1;
    }
    printf("LOG 打开表成功\n");
    //判断账号密码
    char **resultp = NULL;
    int nrow, ncolumn;
    char *sq1 = "select * from user";
    ret = sqlite3_get_table(datebase, sq1, &resultp, &nrow, &ncolumn, &errmsg);
    if (ret != SQLITE_OK)
    {
        printf("LOG 数据库操作失败\n");
        printf("sqlite3_get_table: %s\n", errmsg);
        return -1;
    }
    int flag = 0; //表示账号不存在
    for (int i = 0; i < (nrow + 1) * ncolumn; i += 2)
    {
        if (strcmp(resultp[i], mymsg.sourceName) == 0 && strcmp(resultp[i + 1], mymsg.buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    Msg temp;
    memset(&temp, 0, sizeof(temp));
    if (flag)
    {
        temp.cmd = LOG_OK;
        write(client_socket, &temp, sizeof(temp));
        return 0;
    }
    else
    {
        temp.cmd = LOG_ERROR;
        write(client_socket, &temp, sizeof(temp));
        return -1;
    }
}

