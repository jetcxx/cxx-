#include "seqlist.h"
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
bool SeqlistIsFull(seqlist *st)
{
    return st->pos == N - 1 ? 1 : 0;
}

//判断顺序表是否为空
bool SeqlistIsEmpty(seqlist *st)
{
    return st->pos == -1 ? 1 : 0;
}

//插入数据
void SeqlistInsert(seqlist *st,DataType value)
{
    if(SeqlistIsFull(st))
    {
        printf("插入失败，顺序表为满!\n");
        return;
        }
        //保存最后一个变量的下标
        st->pos++;
        st->data[st->pos] = value;
        printf("插入成功！\n");
        return;
}

//删除尾端数据并返回数据
DataType SeqlistDelete(seqlist *st)
{
    if(SeqlistIsEmpty(st))
    {
        printf("顺序表为空，删除失败！\n");
        return (DataType)-1;
        }
        DataType value = st->data[st->pos];
        st->pos--;
        printf("删除成功！\n");
        return value;
        }


//按照位置插入数据
void SeqlistInsertByPos(seqlist *st,int p,DataType value)
{
    if(SeqlistIsFull(st))
    {
        printf("顺序表为满，插入失败！\n");
        return;
        }
        if(p < 0 || p > st->pos + 1)
        {
            printf("输入位置有误，插入失败！\n");
            return;
            }
            int i;
            if(p == st->pos + 1)
            {
                st->data[p] = value;
                st->pos++;
                }
                else
                {
                    //将p之后的数据依次向上移动
                    for(i = st->pos;i >= p;i--)
                    {
                        st->data[i+1] = st->data[i];
                        }
                        st->data[p] = value;
                        st->pos++;
                        }
                        printf("按照位置插入数据成功\n");
                        }

//遍历顺序表
void SeqlistPrint(seqlist *st)
{
    int i;
    for(i = 0; i <= st->pos;i++)
    {
        printf("%d ",st->data[i]);
        }
        putchar(10);
        }

//按照位置删除数据，返回删除的数据
DataType SeqlistDeleteByPos(seqlist *st,int p)
{
    if(SeqlistIsEmpty(st) == 1)
    {
        printf("删除失败，顺序表为空！\n");
        return (DataType)-1;
        }
        if(p < 0 || p > st->pos)
        {
            printf("删除失败，位置有误！\n");
            return (DataType)-1;
            }
            //保存要删除的数据
            DataType value = st->data[p];
            int i;
            for(i = p;i < st->pos;i++)
            {
                st->data[i] = st->data[i + 1];
                }
                st->pos--;
                printf("按照为hi删除数据成功\n");
                return value;
                }

//删除重复数据
void SeqlistDeletRepeat(seqlist *st)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < st->pos;i++)
    {
        for(j = i+1;j <= st->pos;j++)
        {
            if(st->data[i] == st->data[j])
            {
                SeqlistDeleteByPos(st,j);
                j--;
            }
        }
    }
}
