#include "doublelist.h"

doublelist *DoublelistCreat()
{
    doublelist *head = (doublelist *)malloc(sizeof(doublelist));
    head->front = head;
    head->next = head;
}

void DoublelistInsert(doublelist *head,DataType value)
{
    doublelist *tmp = (doublelist *)malloc(sizeof(doublelist));
    tmp->value = value;

    head->next->front = tmp;
    tmp->next = head->next;
    head->next = tmp;
    tmp->front = head;
}

void DoublelistPrint(doublelist *head)
{
    doublelist *p = head;
    while(p->next != head)
    {
        p = p->next;
        printf("%d ",p->value);
    }
    putchar(10);
}

DataType DoublelistDelHead(doublelist *head)
{
    doublelist *tmp = head->next;
    head->next = tmp->next;
    tmp->next->front = head;
    DataType value = tmp->value;
    free(tmp);
    tmp = NULL;
    return value;
}