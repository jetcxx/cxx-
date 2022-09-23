#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
int print(void *arg,int ncolumn,char**f_value,char**f_name)//column：列数 name:字段名 value:数据
{
    int i;
    for(i = 0 ; i < ncolumn;i++)
    {
        printf(" %s = %s ",f_name[i],f_value[i]);
    }
    printf("\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    sqlite3 *ppdb;
    //打开或者创建数据库
    int ret = sqlite3_open("stu.db",&ppdb);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(ppdb));
        return -1;
    }
    //创建表
    char sql[128] = {0};
    sprintf(sql,"create table if not exists stu(id int,name char,sex char,scoreint);");
    ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
        return -1;
    }
    //插入数据
    int i;
    int id,score;
    char name[32] = {0};
    char sex;
    for(i = 0 ; i < 2;i++)
    {
        printf("请输入学号，姓名，性别，分数：\n");
        scanf("%d%s %c%d",&id,name,&sex,&score);
        memset(sql,0,sizeof(sql));
        sprintf(sql,"insert into stuvalues(%d,'%s','%c',%d);",id,name,sex,score);
        ret = sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
        if(ret != SQLITE_OK)
        {
            printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
            return -1;
        }
    }
    memset(sql,0,sizeof(sql));
    sprintf(sql,"select *from stu;");
/*
  ret = sqlite3_exec(ppdb,sql,print,NULL,NULL);
  if(ret != SQLITE_OK)
  {
    printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
    return -1;
  }
*/
    char **result;
    int row,column;
    ret = sqlite3_get_table(ppdb,sql,&result,&row,&column,NULL);//row:行 column:列
    if(ret != SQLITE_OK)
    {
        printf("sqlite3_get_table:%s\n",sqlite3_errmsg(ppdb));
        return -1;
    }
    int j;
    int Index = column;
    for(i = 0 ; i < row;i++)
    {
        for(j = 0 ; j < column;j++)
        {
            printf(" %s = %s ",result[j],result[Index]);
            Index++;
        }
        putchar(10);
    }
    return 0;
}