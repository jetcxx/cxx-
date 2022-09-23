#include "Looplist.h"

looplist* LooplistCreate()
{
    looplist *head = (looplist *)malloc(sizeof(looplist));
    head->next = head;
    return head;
}

