#ifndef _SEQUEUE_H_
#define _SEQUEUE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;

#define NUM 32
#define N (NUM + 1)

typedef struct
{
    DataType data[N];
    int front;
    int rear;
}sequeue;

sequeue *SequeueCreat();

#endif