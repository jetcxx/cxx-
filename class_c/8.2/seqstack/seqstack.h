#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
#define N 32
typedef struct 
{
    DataType data[N];
    int top;
}seqstack;


#endif