#include <stdio.h>
int main()
{
    int i,m,sum = 0;
    printf("输入一个自然数:");
    scanf("%d",&i);
    for (m = 1;m <= i; ++m)
    {
	sum += m;
    }
    printf("和为:%d",sum);
    return 0;
}
