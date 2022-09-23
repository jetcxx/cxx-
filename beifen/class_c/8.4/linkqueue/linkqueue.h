#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;


typedef struct node
{
    Datatype data;
    struct node *next;
}linknode;

typedef struct
{
    linknode *front;
    linknode *rear;
}linkqueue;

linkqueue *linkqueueCreate();
void LinkqueueInput(linkqueue *q,Datatype value);
Datatype LinkqueueOutput(linkqueue *q);

#endif