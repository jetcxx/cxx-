#include "sequeue.h"

sequeue *SequeueCreat()
{
    sequeue *sq = (sequeue *)malloc(sizeof(sequeue));
    sq->front = sq->rear = 0;
    return sq;
}

bool SequeueIsFull(sequeue *sq)
{
    return (sq->rear + 1)% N == sq->front? 1 : 0;
}

bool SequeueIsEmpty(sequeue *sq)
{
    return sq->front == sq->rear ? 1 : 0;
}