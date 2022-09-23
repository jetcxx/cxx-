#include <stdio.h>
int main()
{
    int a,b,i,m;
    printf("输入两个数:");
    scanf("%d %d",&a,&b);
    for(i = 1;i <= a && i <= b;i++)
    {
	if(a%i == 0 && b%i == 0)
	m = i;
    }
	printf("最大公约数为:%d",m);
    return 0;
}

