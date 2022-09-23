#include "looplist.h"
//创建一个空的单向循环链表
looplist* LoopListCreate()
{
    looplist *head = (looplist *)malloc(sizeof(looplist));
    //赋初始值
    //初始状态就为循环
    //头结点的指针域保存头结点的地址
    head->next = head;
    return head;
}
//插入数据
void LooplistInsert(looplist *head,DataType value)
{
    looplist *tmp = (looplist *)malloc(sizeof(looplist));
    tmp->data = value;
    tmp->next = NULL;
    tmp->next = head->next;
    head->next = tmp;
    return;
}
//遍历单向循环链表
void LooplistPrint(looplist *head)
{
    looplist *p = head;
    while(p->next != head)
    {
        p = p->next;
        printf("%d ",p->data);
        }
        putchar(10);
}
//删除头结点
looplist* LoopListDeleteHead(looplist *head)
{
    looplist *p = head;
    while(p->next != head)
    {
        p = p->next;
        }
        p->next = head->next;
        free(head);
        head = NULL;
        return p->next;
}
//去头结点遍历
void LooplistPrint2(looplist *head)
{
    looplist *p = head;
    while(p->next != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
        }
        printf("%d ",p->data);
        putchar(10);
}