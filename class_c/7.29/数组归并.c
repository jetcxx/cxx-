#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[4] = {8,7,2,9};
    int b[4] = {3,4,6,1};
    int c[8] = {0};
    int i;
    for(i = 0;i < 4;i++)
    {
        c[i] = a[i];
        c[i+4] = b[i];
    }
    for(i = 0;i < 8;i++)
    {
        printf("%d",c[i]);
    }
    putchar(10);
    int j;
    int t = 0;
    for(i = 0;i < 8;i++)
    {
        for(j = 0;j < 8 - i;j++)
        {
            if(c[j] > c[j+1])
            {
                t = c[j];
                c[j] = c[j+1];
                c[j+1] = t;
            }
        }
    }
    for(i = 0;i < 8;i++)
    {
        printf("%d",c[i]);
    }
    putchar(10);
    return 0;
}
