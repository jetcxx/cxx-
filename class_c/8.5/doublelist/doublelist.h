#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node
{
    DataType value;
    struct node *front;
    struct node *next;
}doublelist;

doublelist *DoublelistCreat();
void DoublelistInsert(doublelist *head,DataType value);
void DoublelistPrint(doublelist *head);
DataType DoublelistDelHead(doublelist *head);


#endif