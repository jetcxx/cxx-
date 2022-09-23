#include "doublelist.h"

int main(int argc, char const *argv[])
{
    doublelist *head = DoublelistCreat();
    int i;
    for(i = 1;i < 10;i++)
    {
        DoublelistInsert(head,i);
    }
    int a = DoublelistDelHead(head);
    printf("%d ",a);
    putchar(10);
    DoublelistPrint(head);
    return 0;
}
