#ifndef _SEQLIST_H
#define _SEQLIST_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int DataType; //提高代码的拓展性，可读性
//定义一个结构体
#define N 32 //顺序表的大小
typedef struct
{
    DataType data[N];
    int pos;
}seqlist;



//创建一个空的顺序表
seqlist* SeqlistCreate()
{
    //在堆区申请空间
    seqlist *st = (seqlist *)malloc(sizeof(seqlist));
    //初始化，标识当前顺序表为空
    st->pos = -1;
    //返回顺序表的首地址（堆空间的首地址）
    return st;
}
//判断顺序表是否为满
bool SeqlistIsFull(seqlist *st);
//插入数据
void SeqlistInsert(seqlist *st,DataType value);
//遍历顺序表
void SeqlistPrint(seqlist *st);
DataType SeqlistDelete(seqlist *st);
void SeqlistDelByPos(seqlist *st,int p,DataType value);
void SeqlistInsertByPos(seqlist *st,int p,DataType value);
int SeqlistDelRet(seqlist *st,DataType value);
bool SeqlistIsEmpty(seqlist *st);
#endif