#include "seqstack.h"

int main(int argc, char const *argv[])
{
    seqstack *s = SeqstackCreate();
    int i;
    for(i = 0;i < 10;i++)
    {
        SeqstackPush(s,i);
    }
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",s->data[i]);
    }
    putchar(10);
    DataType a = SeqstackPop(s);
    printf("%d\n",a);
    
    return 0;
}
