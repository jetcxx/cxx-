#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node
{
    DataType data;
    struct node *next;
}linknode;

typedef struct
{
    linknode *front;
    linknode *rear;
}linkqueue;

linkqueue *LinkqueueCreate();
void LinkqueueInput(linkqueue *q,DataType value);
DataType LinkqueueOutput(linkqueue *q);

#endif