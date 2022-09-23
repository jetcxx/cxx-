#include "linkstack.h"
int main(int argc, char const *argv[])
{
    stack s;
    InitStack(&s);
    int i;
    for(i = 0 ; i < 10;i++)
    {
        printf("%d:入栈\n",i+1);
        push(&s,i+1);
        }
        while(!EmptyStack(&s))
        {
            printf("%d 出栈\n",pop(&s));
            }
            Calculator();
            return 0;
}