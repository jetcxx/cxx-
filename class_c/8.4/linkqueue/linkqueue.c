#include "linkqueue.h"

linkqueue *linkqueueCreate()
{
    linkqueue *q = (linkqueue *)malloc(sizeof(linkqueue));
    q->front = (linknode *)malloc(sizeof(linknode));
    q->rear = q->front;

    q->front->next = NULL;

    return q;
}

void LinkqueueInput(linkqueue *q,Datatype value)
{
    linknode *tmp = (linknode *)malloc(sizeof(linknode));
    tmp->next = NULL;
    tmp->data = value;

    q->rear->next = tmp;
    tmp->next = NULL;

    q->rear = tmp;
    return;
}

Datatype LinkqueueOutput(linkqueue *q)
{
    if(q->front->next == NULL)
    {
        printf("队列为空\n");
        return (Datatype)-1;
    }

    linknode *tmp = q->front->next;
    q->front->next = tmp->next;
    Datatype value = tmp->data;

    free(tmp);
    tmp = NULL;

    if(q->front->next == NULL)
    {
        q->rear = q->front;
    }
    return value;
}