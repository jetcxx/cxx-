#include <stdio.h>
int main()
{
    int a,i;
    unsigned long long factorial = 1;
    printf("输入一个正整数:");
    scanf("%d",&a);
    if (a < 0)
	printf("error,不能输入负数");
    else
    {
	for(i = 1;i <= a; ++i)
	{
	    factorial *= i;
	}
	printf("%d! = %llu\n",a,factorial);
    }
    return 0;
}
