#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void InsertSort(int *a,int length)
{
    int i,j,tmp;
    for(i = 1;i < length;i++)
    {
        tmp = a[i];
        for(j = i - 1;j >= 0;j--)
        {
            if(tmp < a[j])
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
            
        }
        a[j + 1] = tmp;
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
    InsertSort(array,length);
    for ( i = 0; i < length; i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
    return 0;
}
