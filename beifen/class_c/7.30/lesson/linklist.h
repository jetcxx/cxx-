#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdlib.h>
#include <stdio.h>

typedef int DataType;
typedef struct node
{
    DataType data;
    struct node *next;   
}linklist;

linklist *LinklistCreat();
void LinklistInsertHead(linklist*head,DataType value);
void LinklistPrint(linklist *head);
void LinklistInsertBypos(linklist *head,DataType pos,DataType value);
void LinklistSearchBydata(linklist *head,DataType data);

#endif