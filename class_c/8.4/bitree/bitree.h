#ifndef _BITREE_H_
#define _BITREE_H_

#include <stdlib.h>
#include <stdio.h>

typedef int Datatype;

typedef struct tree
{
    Datatype data;
    struct tree *left;
    struct tree *right;
}Node;


#endif