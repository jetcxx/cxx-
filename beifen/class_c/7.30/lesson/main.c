#include "linklist.h"
int main(int argc, char const *argv[])
{
    int i;
    linklist *LinklistCreat();
    for(i = 0;i < 10;i++)
    {
        LinklistInsertHead(head,10);
    }
    LinklistPrint(9);
    return 0;
}
