#include "linklist.h"


int main(int argc, char const *argv[])
{
    int i;
    linklist *head = LinklistCreate();
    for(i = 0;i<11;i++)
    {
        LinklistInsertTail(head,i);
        //LinklistInsertHead(head,i);
    }
    //LinklistDelHead(head);
    Linklistupdate(head,5,555);
    LinklistSearchBypos(head,3);
    LinklistSearchBydata(head,8);
    LinklistInsertBypos(head,999,9);
    LinklistPrint(head);
    return 0;
}
