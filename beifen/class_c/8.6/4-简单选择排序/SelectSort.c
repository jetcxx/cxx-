#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void SelectSort(int *a,int length)
{
    int i,j,tmp,index;
    for(i = 0;i < length - 1;i++)
    {
        tmp = a[i];
        index = i;
        for(j = i + 1;j < length;j++)
        {
            if(a[j] < tmp)
            {
                tmp = a[j];
                index = j;
            }
        }
        if(index != i)
        {
            a[index] = a[i];
            a[i] = tmp;
        }
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
    SelectSort(array,length);
    for ( i = 0; i < length; i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
    return 0;
}
