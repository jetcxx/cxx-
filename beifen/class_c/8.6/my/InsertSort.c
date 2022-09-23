#include <stdio.h>

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
    int a[10] = {3,1,8,5,7,6,2,4,0,9};
    int i;
    int length = sizeof(a)/sizeof(int);
    InsertSort(a,length);
    for(i = 0;i < length;i++)
    {
        printf("%d ",a[i]);
    }
    putchar(10);
    return 0;
}
