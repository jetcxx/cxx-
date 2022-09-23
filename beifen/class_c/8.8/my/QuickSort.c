#include <stdio.h>

void QuickSort(int *a,int start,int end)
{
    int x = start;
    int y = end;
    int base = a[start];
    if(start >= end)
    {
        return;
    }
    while (x < y)
    {  
        while (a[y] > base && x < y)
        {
            y--;
        }
        if (x < y)
        {
            a[x] = a[y];
        }
        while (a[x] < base && x < y)
        {
            x++;
        }
        if(x < y)
        {
            a[y] = a[x];
        }
        a[x] = base;
    }
    QuickSort(a,start,x - 1);
    QuickSort(a,x + 1,end);
}

int main(int argc, char const *argv[])
{
    int a[10] = {9,7,8,6,5,3,4,2,1,0};
    int length = sizeof(a)/sizeof(int);
    QuickSort(a,0,length - 1);
    for(int i = 0;i < length;i++)
    {
        printf("%d ",a[i]);
    }
    putchar(10);
    return 0;
}
