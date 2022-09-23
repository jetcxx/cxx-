#include <stdio.h>
int main()
{
    int a[] = {10,20,30,40,50,60,70,80,90};
    printf("sizeof(a) = %ld\n",sizeof(a[0]));

    int i;
    int length = sizeof(a)/sizeof(a[0]);
    for(i = 0;i < length;i++)
    {
	printf("%d ",a[i]);
    }
    putchar(10);
    return 0;
}
