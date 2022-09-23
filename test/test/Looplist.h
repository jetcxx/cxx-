#ifndef _LOOPLIST_H_
#define _LOOPLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int DataType;
//定义结点结构体
typedef struct node
{
    DataType data; //数据域
    struct node *next; //指针域
}looplist;

#endif