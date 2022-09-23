#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int DataType;


typedef struct node //表示结点信息
{
    DataType data;
    struct node *next;
}Node;


typedef struct Stack //表示栈的信息
{
    Node *top;
    int length;
}stack;


//创建一个空的链栈
void InitStack(stack *s);
//入栈
void push(stack *s,DataType num);
//出栈
DataType pop(stack *s);
//获取栈顶元素
DataType GetTop(stack *s);

int Priority(char ch);

void Calculator();
#endif