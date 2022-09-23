#include <stdio.h>
int main()
{
    int a[10] = {0};
    int length = sizeof(a)/sizeof(a[0]);
    printf("输入10个数字:\n");
    int i,j;
    for(i = 0;i < length;i++)
    {
	scanf("%d",&a[i]);
    }
    for(i = 0;i < length-1;i++)
    {
	for(j = 0;j < length-1;j++)
	{
	    if(a[j] > a[j + 1])
	    {
		int t = a[j];
		a[j] = a[j + 1];
		a[j + 1] = t;
	    }
	}
    }
    for(i = 0;i < length;i++)
    {
	printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
