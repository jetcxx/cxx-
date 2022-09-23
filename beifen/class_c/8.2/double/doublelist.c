#include "doublelist.h"
//创建一个空的双向循环链表
doublelist * DoubleListCreate()
{
    //在堆区开辟空间
    doublelist *head = (doublelist *)malloc(sizeof(doublelist));
    //让头结点的两个指针保存头结点的地址
    head->front = head;
    head->next = head;
    return head;
}
//插入数据
void DoubleListInsert(doublelist *head,DataType value)
{
    doublelist *tmp = (doublelist *)malloc(sizeof(doublelist));
    tmp->value = value;
    tmp->next = head->next;
    tmp->front = head;
    head->next = tmp;
    tmp->next->front = tmp;
}
//遍历链表
void DoubleListPrint(doublelist *head)
{
    doublelist *p = head;
    while(p->next != head)
    {
        p = p->next;
        printf("%d ",p->value);
        }
        putchar(10);
}