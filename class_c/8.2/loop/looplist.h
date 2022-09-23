#ifndef _LOOPLIST_H_
#define _LOOPLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int DataType;
//定义结点结构体
typedef struct node
{
    DataType data;//数据域
    struct node *next;//指针域
}looplist;
//创建一个空的单向循环链表
looplist * LoopListCreate();
//插入数据
void LooplistInsert(looplist *head,DataType value);
//遍历单向循环链表
void LooplistPrint(looplist *head);
//删除头结点
looplist* LoopListDeleteHead(looplist *head);
//去头结点遍历
void LooplistPrint2(looplist *head);
#endif