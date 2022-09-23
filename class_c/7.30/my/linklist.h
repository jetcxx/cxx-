#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int Datatype;
typedef struct node
{
    Datatype data;
    struct node *next;
}linklist;

linklist * LinklistCreate();
void LinklistInsertHead(linklist *head,Datatype value);
void LinklistPrint(linklist *head);
void LinklistInsertTail(linklist *head,Datatype value);
bool LinklistIsEmpty(linklist *head);
Datatype LinklistDelHead(linklist *head);
void Linklistupdate(linklist *head,Datatype olddata,Datatype newdata);
void LinklistSearchBypos(linklist *head,Datatype pos);
void LinklistSearchBydata(linklist *head,Datatype data);
void LinklistInsertBypos(linklist *head,Datatype value,Datatype pos);



#endif