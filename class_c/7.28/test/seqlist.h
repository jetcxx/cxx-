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

seqlist* SeqlistCreate();
bool SeqlistIsFull(seqlist *st);
void SeqlistInsert(seqlist *st,DataType value);
void SeqlistPrint(seqlist *st);
bool SeqlistIsEmpty(seqlist *st);
DataType SeqlistDelete(seqlist *st);
void SeqlistInsertByPos(seqlist *st,int p,DataType value);
void SeqlistDeletRepeat(seqlist *st);
DataType SeqlistDeleteByPos(seqlist *st,int p);

#endif