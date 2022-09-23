#include "seqstack.h"

seqstack *SeqstackCreate()
{
    seqstack *s = (seqstack *)malloc(sizeof(seqstack));
    s->top = -1;
}

bool SeqstackIsFull(seqstack *s)
{
    return s->top == N ? 1 : 0;
}

bool SeqstackIsEmpty(seqstack *s)
{
    return s->top == -1 ? 1 : 0;
}

void SeqstackPush(seqstack *s,DataType value)
{
    if(SeqstackIsFull(s))
    {
        printf("栈满了\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
    return;
}

DataType SeqstackPop(seqstack *s)
{
    if(SeqstackIsEmpty(s))
    {
        printf("栈为空\n");
        return (DataType)-1;
    }
    DataType value = s->data[s->top];
    s->top--;
    return value;
}