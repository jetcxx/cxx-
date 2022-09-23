#include "seqlist.h"
int main(void)
{
    seqlist *s = SeqlistCreate();
    int i;
    for(i = 0 ; i < 10;i++)
    {
        SeqlistInsert(s,i+1);
        }
        SeqlistPrint(s);
}