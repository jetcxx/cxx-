#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *a,int start,int end)
{
    if(start >= end)
    {
        return;
    }
    int x = start;
    int y = end;
    int base = a[start];
    while (x < y)
    {
        while (a[y] > base && x < y)
        {
            y--;
        }
        if(x < y)
        {
            a[x++] = a[y];
        }
        while (a[x] < base && x < y)
        {
            x++;
        }
        if(x < y)
        {
            a[y--] = a[x];
        }
    }
    a[x] = base;
    QuickSort(a,start,x-1);
    QuickSort(a,x+1,end);
    
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
    QuickSort(array,0,length-1);
    for ( i = 0; i < length; i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
    return 0;
}
