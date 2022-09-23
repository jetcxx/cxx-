#include "contact.h"
 int count;


linklist *head = NULL;

void InitList()
{
	head = (linklist *)malloc(sizeof(linklist));
	head->next = NULL;
	printf("初始化成功!\n");
}

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
        linklist *node; //插入节点
        int flag = 1;//用于判断是否继续输入下一条记录
        while (flag)
        {
            count++;
            node = (linklist *)malloc(sizeof(linklist));
            printf("插入第%d条记录：\n", count);
            printf("id：");
            scanf("%d",&(node->data.id));
            printf("姓名：");
            scanf("%s",node->data.name);
            printf("电话：");
            scanf("%s",node->data.num);
            node->next = head->next;
            head->next = node;
            printf("是否继续录入(1.继续 0.完成录入)：");
            scanf("%d", &flag);
            if (flag == 0)
            break;
            }
            }
    
}

void View()
{
    linklist *p = head->next;
    while (p)
    {
        printf("%d %s %s\n",p->data.id,p->data.name,p->data.num);
        p = p->next;
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
    char name[10];
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("输入联系人id:\n");
        scanf("%d",&x);
        linklist *p = head->next;
        while(p && x != p->data.id)
        {
            p = p->next;
        }
        if(p == NULL)
        {
            printf("通讯录不存在此人\n");
            return;
        }
        else
        {
            printf("ID：%d\t",p->data.id);
		    printf("姓名：%s\t",p->data.name);
		    printf("电话：%s\n",p->data.num);
        }
        
        break;
    case 2:
    printf("请输入要查找的name：");
	scanf("%s", name);
    linklist *q = head->next;
	//char name[10];
	//q = head->next;
	while (q && mystrcmp(q->data.name,name) != 0)
	{
		q = q->next;
	}
	if (q == NULL)
	{
		printf("通讯录中不存在此人！\n");
		return;
	}
	else
	{
		printf("ID：%d\t", q->data.id);
		printf("姓名：%s\t", q->data.name);
		printf("电话：%s\n", q->data.num);
	}
        default:
        break;
    }
}


void Del()
{
    linklist *p = head->next;
	linklist *q = head;
	Datatype id;
	printf("请输入要删除的id：");
	scanf("%d",&id);
	while (p && id != p->data.id)
	{
		p = p->next;
		q = q->next;
	}
	if (p)
	{
		q->next = p->next;
		printf("删除成功!\n");
		printf("被删除数据的信息为：\n");
		printf("id：%d\n", p->data.id);
		printf("姓名：%s\n", p->data.name);
		printf("电话：%s\n", p->data.num);
        count--;
		free(p);
	}
	else
	{
		printf("通讯录中不存在此人信息！\n");
	}

}

void Revise()
{
linklist *p;
	p = head->next;
	Datatype id;
	printf("请输入要修改的ID:");
	scanf("%d", &id);
	while (p && id != p->data.id)
	{
		p = p->next;
	}
	if (p != NULL)
	{
		int choice;
		printf("请输入需要修改的属性(1.姓名 2.电话)：");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("请输入新的姓名：");
			scanf("%s", p->data.name);
		}
		if (choice == 2)
		{
			printf("请输入新的电话：");
			scanf("%s", p->data.num);
		}
		printf("更新成功！\n");
	}
	else
	{
		printf("通讯录中不存在该ID!\n");
		return;
	}
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

