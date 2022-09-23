#include "bitree.h"

Node *CreatTree(int *a,int length)
{
    Node *array[11] = {0};
    int i;
    for(i = 0;i < length;i++)
    {
        array[i] = (Node *)malloc(sizeof(Node));
        if(NULL == array[i])
        {
            printf("malloc array[%d] failure!\n",i);
            return NULL;
        }
        array[i]->data = a[i];
        array[i]->left = NULL;
        array[i]->right = NULL;
    }
    for(i = 0;i < length/2;i++)
    {
        array[i]->left = array[2 * i + 1];
        array[i]->right = array[2 * i + 2];
    }
    return array[0];
}

void Preorder(Node *root)
{
    if(NULL == root)
    {
        return;
    }
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}