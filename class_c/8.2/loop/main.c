#include "looplist.h"
int main(int argc, char const *argv[])
{
    looplist *head = LoopListCreate();
    int i;
    for(i = 0 ; i < 10;i++)
    {
        LooplistInsert(head,i+1);
        }
        LooplistPrint(head);
        head = LoopListDeleteHead(head);
        LooplistPrint2(head);
        return 0;
}