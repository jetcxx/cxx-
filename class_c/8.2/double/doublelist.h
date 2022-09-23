#ifndef _DOUBLElIST_H_
#define _DOUBLELIST_H_
#include <stdio.h>
#include <stdlib.h>
//定义数据类型
typedef int DataType;
//定义结点结构体
typedef struct node
{
    DataType value;
    struct node *front;//保存前一个结点的地址
    struct node *next;//保存后一个结点的地址
}doublelist;
//创建一个空的双向循环链表
doublelist * DoubleListCreate();
//插入数据
void DoubleListInsert(doublelist *head,DataType value);
//遍历链表
void DoubleListPrint(doublelist *head);
#endif