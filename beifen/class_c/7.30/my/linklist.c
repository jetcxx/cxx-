#include "linklist.h"


linklist * LinklistCreate()
{
    linklist *head = (linklist *)malloc(sizeof(linklist));
    head->next = NULL;
    return head;
}

void LinklistInsertHead(linklist *head,Datatype value)
{
    linklist *tmp = (linklist*)malloc(sizeof(linklist));
    tmp->next = NULL;
    tmp->data = value;
    tmp->next = head->next;
    head->next = tmp;
    return;
}

void LinklistPrint(linklist *head)
{
    linklist *p = head->next;
    while(p->next != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}

void LinklistInsertTail(linklist *head,Datatype value)
{
    linklist *tmp = (linklist*)malloc(sizeof(linklist));
    tmp->next = NULL;
    tmp->data = value;
    linklist *p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    tmp->next = p->next;
    p->next = tmp;
    return;
}

bool LinklistIsEmpty(linklist *head)
{
    return head->next == NULL ? 1 : 0;
}

Datatype LinklistDelHead(linklist *head)
{
    if (LinklistIsEmpty(head))
    {
        printf("删除失败，链表为空\n");
    }
    Datatype value = head->next->data;
    linklist *tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    tmp = NULL;
    return value;
}

void Linklistupdate(linklist *head,Datatype olddata,Datatype newdata)
{
    if(LinklistIsEmpty(head))
    {
        printf("链表为空\n");
        return;
    }
    linklist *p = head;
    while(p->next != NULL)
    {
        p = p->next;
        if(p->data == olddata)
        {
            p->data = newdata;
        }
    }
    return;
}

void LinklistSearchBypos(linklist *head,Datatype pos)
{
    if(LinklistIsEmpty(head))
    {
        printf("链表为空\n");
        return;
    }
    linklist *p = head;
    int i;
    for(i = 0;i < 11;i++)
    {
        p = p->next;
        if(i == pos-1)
        {
            printf("%d\n",p->data);
        }
    }
    
}

void LinklistSearchBydata(linklist *head,Datatype data)
{
    if(LinklistIsEmpty(head))
    {
        printf("链表为空\n");
        return;
    }
    Datatype pos = 0;
    linklist *p = head;
    while(p->next != NULL)
    {
        p = p->next;
        pos++;
        if(p->data == data)
        {
            printf("%d\n",pos);
        }
    }
    return;
}

void LinklistInsertBypos(linklist *head,Datatype value,Datatype pos)
{
    linklist *tmp = (linklist*)malloc(sizeof(linklist));
    tmp->next = NULL;
    tmp->data = value;
    if(LinklistIsEmpty(head))
    {
        tmp->next = head->next;
        head->next = tmp;
    }
    linklist *p =head;
    int i = 0;
    while(p->next != NULL)
    {
        p = p->next;
        i++;
        if(i == pos)
        {
            tmp->next = p->next;
            p->next = tmp;
        }
    }
}
