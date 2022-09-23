#include "contact.h"
extern person *ct[MAX];
extern int count;

void Welcome()
{
    printf("--------------------------------------------------------------------------------\n");
    printf("                                    欢迎使用                               \n");
    printf("---------------------------------------------------------------------------------\n");
}

void Menu()
{
    printf("----------------------------------------------------------------------------------\n");
    printf("        a.添加用户                                       b.查看用户             \n");
    printf("        c.搜索用户                                       d.删除用户信息    \n");
    printf("        e.修改用户信息                                   f.退出                         \n");
    printf("----------------------------------------------------------------------------------\n");
    printf("输入操作指令:\n");
}

void Add()
{
    if(count >= MAX)
    {
        printf("通讯录已满\n");
        return;
    }
    else
    {
        //person *p = (person *)malloc(sizeof(person));
        person *pt = NULL;
        pt = (person *)malloc(sizeof(person));
        ct[count] = pt;
        printf("输入id:\n");
        scanf("%d",&(pt->id));
        printf("输入姓名:\n");
        scanf("%s",pt->name);
        printf("输入电话:\n");
        scanf("%s",pt->num);
        printf("添加成功\n");
        count++;
        return;
    }
    
}
void sort()
{
    int i = 0;
    int j = 0;
    person *tmp = NULL;
    for(i = 0;i < count - 1;i++)
    {
        for(j = 0;j < count -1 - i;j++)
        {
            if(mystrcmp(ct[j]->name,ct[j+1]->name) > 0)
            {
                tmp = ct[j];
                ct[j] = ct[j+1];
                ct[j+1] = tmp;

                tmp = NULL;
                break;
            }
        }
    }
}

void View()
{
    int i;
    for(i = 0;i < count;i++)
    {
        printf("%d %s %s\n",ct[i]->id,ct[i]->name,ct[i]->num);
    }
    printf("共%d位联系人\n",count);
}

void Search()
{
    printf("输入查找方式:1.按id查找\t2.按姓名查找\n");
    int a;
    int i = 0;
    int j = 0;
    int x;
    char name[32];
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("输入联系人id:\n");
        scanf("%d",&x);
       /* for(i = 0;i <= count;i++)
        {
            if (x == ct[i]->id)
            {
                printf("%d\t%s\t%s\n",ct[i]->id,ct[i]->name,ct[i]->num);
            }
            else
            {
                printf("未查找到此ID\n");
                break;
            }*/
            while(i != 100)
            {
                if (x == ct[i]->id)
            {
                printf("%d\t%s\t%s\n",ct[i]->id,ct[i]->name,ct[i]->num);
                break;
            }
                i++;
            }
        break;
    case 2:
    printf("输入联系人姓名:\n");
    scanf("%s",name);
    /*for(i = 0;i < count;i++)
    {
        int ret = mystrcmp(name,ct[i]->name);
        if(ret == 0)
        {
             printf("%d\t%s\t%s\n",ct[i]->id,ct[i]->name,ct[i]->num);
        }
        else
        {
            printf("未查找到此联系人\n");
            break;
        }
        
    }*/
    while(j != 100)
    {
         int ret = mystrcmp(name,ct[j]->name);
        if(ret == 0)
        {
             printf("%d\t%s\t%s\n",ct[j]->id,ct[j]->name,ct[j]->num);
             break;
        }
        j++;
    }
    
    default:
        break;
    }
}

void Del()
{
    /*printf("输入要删除的联系人姓名:\n");
    char name[32];
    scanf("%s",name);
    int i = 0;
    int j = 0;
    int ret = 0;
    person *tmp = ct[i];
        while(i < count)
        {
            ret = mystrcmp(name,ct[i]->name);
            if(ret == 0)
            {
                free(tmp);
                tmp = NULL;
                j = i;
                for(i = j;i < count - 1;i++)
                {
                ct[i] = ct[i+1];
                }
                printf("删除成功\n");
            }
            i++;
        }
        ct[count] = NULL;
        count--;*/
        int i,j;
    char name[32];
    printf("请输入联系人姓名：");
    scanf("%s",name);
    for ( i = 0; i < count; i++)
    {
        if (mystrcmp(name,ct[i]->name) == 0)
        {
            j = i;
            printf("删除成功\n");
            break;             
        }                                           
    }
    person *tmp = ct[j];
    for ( i = j; i < count - 1; i++)
    {
        ct[i] = ct[i+1];
    }
    free(tmp);
    tmp = NULL;
    count--;
    ct[count] = NULL;
}

void Revise()
{
    char name[32] = {0};
     printf("输入联系人姓名：\n");
    scanf("%s",name);
    int i = 0;
    while(i != 100)
    {
        if (mystrcmp(name,ct[i]->name) == 0)
        {
            printf("输入要修改的电话:\n");
            scanf("%s",ct[i]->num);
            printf("修改成功！\n");
            break;
        }
        i++;
    }
    /*for ( i = 0; i <= count; i++)
    {
        if (mystrcmp(name,ct[i]->name) == 0)
        {
            printf("输入要修改的电话:\n");
            scanf("%s",ct[i]->num);
            printf("修改成功！\n");
            break;
        }
        else
        {
            printf("输入错误");
            break;
        }
    }*/
    return;
}


int mystrcmp(char s1[],char s2[])
{
    int i;
    for(i = 0;s1[i] != '\0' || s2[i] != '\0';i++)
    {
        if(s1[i] == s2[i])
        continue;
        else
        {
            return s1[i] - s2[i];
        }
        
    }
}

int mystrlen(char s3[])
{
    int i = 0;
    while (*s3 != '\0')
    {
        i++;
        s3++;
    }
    return i;
}