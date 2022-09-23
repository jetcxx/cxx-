#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void AdjustHeapSort(int *a,int root,int last)
{
    int child,tmp = a[root];
    for(;2*root + 1 <= last;root = child)
    {
        child = 2*root + 1;
        if(child + 1 <= last && a[child] < a[child + 1])
        {
            child++;
        }
        if(a[child] > a[root])
        {
            a[root] = a[child];
            a[child] = tmp;
        }
    }
    
}

void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void HeapSort(int *a,int length)
{
    int i;
    for(i = length / 2 - 1;i >= 0;i--)
    {
        AdjustHeapSort(a,i,length - 1);
    }
    for(i = length - 1;i > 0;i--)
    {
        Swap(&a[0],&a[i]);
        AdjustHeapSort(a,0,i - 1);
    }
}

int main(int argc, char const *argv[])
{
    int i;
    int array[10000] = {0};
    srand(time(NULL));
    for(i = 0;i < 10000;i++)
    {
        array[i] = rand() % 1000;
    }
    int length = sizeof(array)/sizeof(int);
    HeapSort(array,length);
    for ( i = 0; i < length; i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
    return 0;
}
