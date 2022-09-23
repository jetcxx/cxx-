#include "seqstack.h"

seqstack *SeqStackCreate()
{
    seqstack *s = (seqstack *)malloc(sizeof(seqstack));
    s->top = -1;
}