#include "linkstack.h"


void InitLinkstack(stack *s)
{
    s->top = NULL;
    s->length = 0;
}

void Push(stack *s,DataType num)
{
    if(s == NULL)
    {
        return;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = num;
    tmp->next = NULL;

    tmp->next = s->top;
    s->top = tmp;
    s->length++;
}

DataType GetTop(stack *s)
{
    if(s == NULL)
    {
        return (DataType)-1;
    }
    if(s->top == NULL)
    {
        return (DataType)-1;
    }
    return s->top->data;
}

DataType Pop(stack *s)
{
    if(s == NULL)
    {
        return (DataType)-1;
    }
    if(s->top == NULL)
    {
        return (DataType)-1;
    }
    Node *tmp = s->top;
    DataType value = tmp->data;
    s->top = tmp->next;
    free(tmp);
    tmp = NULL;
    s->length--;
    return value;
}

int EmptyStack(stack *s)
{
    if(NULL == s)
    {
        return 1;
    }
    return s->top == NULL ? 1 : 0;
}