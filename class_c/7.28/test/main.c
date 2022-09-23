#include "seqlist.h"
int main()
{
    seqlist *s = SeqlistCreate();
    int i;
    for(i = 0 ; i < 10;i++)
    {
        SeqlistInsert(s,i+1);
        }
        SeqlistDelete(s);
        SeqlistInsertByPos(s,3,333);
        SeqlistPrint(s);
}