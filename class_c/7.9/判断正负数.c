#include <stdio.h>
int main()
{
    double num;
    printf("输入一个数:\n");
    scanf("%lf",&num);
    if (num <= 0)
    {
	if (num == 0)
	    printf("等于零\n");
	else
	    printf("是负数\n");
    }
    else
	printf("是正数\n");
    return 0;
}
