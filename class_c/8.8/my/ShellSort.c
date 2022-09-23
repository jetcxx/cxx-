#include <stdio.h>

void ShellSort(int *a,int length)
{
    int i,j,h,tmp;
    for(h = length/2;h > 0;h /= 2)
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
    int a[10] = {9,8,7,5,6,3,1,4,2,0};
    int length = sizeof(a)/sizeof(int);
    ShellSort(a,length);
    for(int i = 0;i < length;i++)
    {
        printf("%d ",a[i]);
    }
    putchar(10);
    return 0;
}
