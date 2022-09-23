#include <stdio.h>

void SelectSort(int *a,int length)
{
    int i,j,index,tmp;
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
        if(i != index)
        {
            a[index] = a[i];
            a[i] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[10] = {9,8,7,6,4,5,3,1,2,0};
    int length = sizeof(a)/sizeof(int);
    SelectSort(a,length);
    for(int i = 0;i < length;i++)
    {
        printf("%d ",a[i]);
    }
    putchar(10);
    return 0;
}
