#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;
typedef struct node
{
    DataType data;
    struct node *next;
}Node;

typedef struct Stack
{
    Node *top;
    int length;
}stack;

void InitLinkstack(stack *s);
void Push(stack *s,DataType num);
DataType GetTop(stack *s);
DataType Pop(stack *s);
int EmptyStack(stack *s);

#endif