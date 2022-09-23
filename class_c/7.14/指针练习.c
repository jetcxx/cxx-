#include <stdio.h>
int main()
{
    int a[6] = {10,20,30,40,50,60};
    int *m = &a[2];
    int *n = &a[4];
    *m = 888;
    *n = 666;
    int i;
    for(i = 0;i < 6;i++)
    {
	printf("%d \n",a[i]);
    }
    return 0;
}


