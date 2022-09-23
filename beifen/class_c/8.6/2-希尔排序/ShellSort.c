#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void ShellSort(int *a,int length)
{
    int i,j,h,tmp;
    for (h = length/2;h > 0;h /= 2)
    {
        for(i = h;i < length;i++)
        {
            tmp = a[i];
            for(j = i - h;j >= 0;j -= h)
            {
                if(tmp < a[j])
                {
                    a[j + h] = a[j];
                }
                else
                {
                    break;
                }
                
            }
            a[j + h] = tmp;
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
    ShellSort(array,length);
    for ( i = 0; i < length; i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
    return 0;
}
