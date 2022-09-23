#include "doublelist.h"
int main(int argc, char const *argv[])
{
    doublelist *head = DoubleListCreate();
    int i;
    for(i = 0 ; i < 10;i++)
    {
        DoubleListInsert(head,i+1);
        }
        DoubleListPrint(head);
        return 0;
}