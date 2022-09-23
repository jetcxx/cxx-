#include "seqlist.h"

//判断顺序表是否为满
bool SeqlistIsFull(seqlist *st)
{
#if 0
  if(st->pos == N -1)
 {
    return 1;
 }
  else
 {
    return 0;
 }
#endif
return st->pos == N - 1 ? 1 : 0;
}

//判断顺序表是否为空
bool SeqlistIsEmpty(seqlist *st)
{
    return st->pos == -1 ? 1 : 0;
}

//删除数据并返回数据
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

//按位置删除数据并返回
void SeqlistDelByPos(seqlist *st,int p,DataType value)
{
    if (SeqlistIsEmpty(st))
    {
    printf("顺序表为空，删除失败！\n");
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
            for(i = st->pos;i >= p;i--)
            {
                st->data[i] = st->data[i+1];
            }
        }

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

//删除重复数据
void SeqlistDel(seqlist *st)
{
    if(SeqlistIsEmpty(st))
    {
        printf("删除失败\n");
        return;
    }
    int i;
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