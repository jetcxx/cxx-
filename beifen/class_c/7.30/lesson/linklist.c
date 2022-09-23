#include "linklist.h"

linklist *LinklistCreat()
{
    linklist *head = (linklist*)malloc(sizeof(linklist));
    head->next = NULL;
    return head;
}

//头插法
void LinklistInsertHead(linklist*head,DataType value)
{
    linklist *tmp = (linklist*)malloc(sizeof(linklist));
    tmp->next = NULL;
    tmp->data = value;
    //head->next:头结点后面一个结点的地址
    //tmp->next：新插入结点的指针域
    tmp->next = head->next;
    //tmp：新插入结点的地址
    head->next = tmp;
    return;
}

//尾插法
/*void LinklistInsertTail(linklist*head,DataType value)
{
    linklist *tmp = (linklist*)malloc(sizeof(linklist));
    tmp->next = NULL;
    tmp->data = value;
    linklist *p = head->next;
    while(p->next != NULL)
    {

    }
    printf("%d\n",p->data);
}*/

//遍历单链表
void LinklistPrint(linklist *head)
{
    //定义一个指针遍历保存第一个有数据的结点的地址
    linklist *p = head->next;
    //循环遍历单链表，直到p的指针域为空，结束循环遍历
    while(p->next != NULL)
    {
        printf("%d ",p->data);
        //p指向下一个结点（p保存下一个结点的地址）
        p = p->next;
        }
        printf("%d\n",p->data);
}
//按位置插入数据
void LinklistInsertBypos(linklist *head,DataType pos,DataType value)
{
    linklist *p = head->next;
    while(p->next != pos)
    {
        p = p->next;
    }
    linklist *tmp = (linklist*)malloc(sizeof(linklist));
    tmp->next = NULL;
    tmp->data = value;
    tmp->next = p->next;
    p->next = tmp;
    return;
}

//按数据查找位置
void LinklistSearchBydata(linklist *head,DataType data)
{
    linklist *p = head->next;
    while(p->next != NULL)
    {
        if(p->data == data)
        {
            return p->next;
        }
        p = p->next;
    }
}