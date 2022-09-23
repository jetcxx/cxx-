#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef int DataType;
#define N 32

typedef struct
{
    DataType data[N];
    int top;
}seqstack;

seqstack *SeqstackCreate();
bool SeqstackIsFull(seqstack *s);
bool SeqstackIsEmpty(seqstack *s);
void SeqstackPush(seqstack *s,DataType value);
DataType SeqstackPop(seqstack *s);

#endif