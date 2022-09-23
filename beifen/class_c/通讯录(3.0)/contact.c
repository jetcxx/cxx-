#include "contact.h"

int count;

void Menu()
{
    STAT:
    printf("----------------------------------------------------------------------------------\n");
    printf("        a.添加用户                                       b.查看用户             \n");
    printf("        c.搜索用户                                       d.删除用户信息    \n");
    printf("        e.修改用户信息                                   f.退出                         \n");
    printf("----------------------------------------------------------------------------------\n");
    printf("输入操作指令:\n");
}
int Add()
{
    printf("请输入id\n");
    scanf("%d",&p1.id);
    printf("请输入姓名\n");
    scanf("%s",p1.name);
    printf("请输入手机号码\n");
    scanf("%s",p1.num);
    FILE *fp = fopen("./user.txt","a");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    if(1 != fwrite(&p1,sizeof(p1),1,fp))
    {
        perror("fwrite");
        return -1;
    }
    fclose(fp);
    printf("写入结束，正在跳转菜单\n");
    count++;
    sleep(1);
    Menu();
}

int View()
{
    FILE *fp = fopen("user.txt","r");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    for(int i = 0;i < 5;i++)
    {
    if(0 == fread(&p2,sizeof(p2),1,fp))
    {
        if(feof(fp))
        {
            printf("读到文件末尾\n");
        }
        else
        {
            perror("fread");
            return -1;
        }
    }
    else
    {   
        
        printf("姓名：%s\n",p2.name);
        printf("id：%d\n",p2.id);
        printf("联系方式：%s\n",p2.num);
        //Menu();
    }}
    printf("有%d人\n",count);
    Menu();
}

int Search()
{
    char name[32] = {0};
    char num[12] = {0};
    printf("请输入要查询的人的姓名\n");
    scanf("%s",name);
    FILE *fp = fopen("./user.txt","r");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    //循环读取
    while(1)
    {
        if(0 == fread(&p2,sizeof(p2),1,fp))
        {
            if(feof(fp))
            {
                printf("读到文件末尾\n");
                break;
            }
            else
            {
                perror("fread");
                return -1;
            }
        }
        if(strcmp(name,p2.name) == 0)
        {
            printf("姓名：%s\n",p2.name);
            printf("id：%d\n",p2.id);
            printf("联系方式：%s\n",p2.num);
            Menu();
            break;
        }
    }
    return 0;
}

void Del()
{
    int id;
    printf("要删除的id:");
    scanf("%d",&id);
    //FILE *fp = fopen("./user.txt","r+");
    //FILE *fp1 = fopen("./tmp.txt","w+");
    /*while(fread(&p2,sizeof(p2),1,fp))
    {
        if(id != p2.id)
        {
            fwrite(&p2,sizeof(p2),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    fp1 = fopen("./tmp.txt","w+");
    fp = fopen("./user.txt","r");
    while (fread(&p2,sizeof(person),1,fp1))
    {
        fwrite(&p2,sizeof(person),1,fp);
    }
    fclose(fp);
    fclose(fp1);*/
    FILE *fp = fopen("user.txt", "r+");
    FILE *fp1 = fopen("tmp.txt", "w+");//读写新建一个临时文件
    while (fread(&p1, sizeof(person), 1, fp))//从原文件读一个结点
    {
        if (id != p1.id)//不是要删除的内容
        {
            fwrite(&p1, sizeof(person), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("user.txt");                
    rename("tmp.txt", "user.txt");
    count--;
    printf("删除成功\n");
    Menu();
}

void Revise()
{
    int id;
    printf("要修改的id:");
    scanf("%d",&id);
    FILE *fp = fopen("user.txt", "r");
    FILE *fp1 = fopen("tmp.txt", "w");//读写新建一个临时文件
    person p3;
    char buf[123] = {0};
    printf("要修改的姓名:\n");
    scanf("%s",p3.name);
    printf("要修改的电话号码:\n");
    scanf("%s",p3.num);
    p3.id = id;
    while (fread(&p2,sizeof(p2),1,fp))
    {
        if (id == p2.id)
        {
            fwrite(&p3,sizeof(p3),1,fp1);
        }
        else
        {
            fwrite(&p2,sizeof(p2),1,fp1);
        } 
    }
    fclose(fp);
    fclose(fp1);
    remove("user.txt");                
    rename("tmp.txt", "user.txt");
    Menu();

}

