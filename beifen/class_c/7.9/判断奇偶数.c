#include <stdio.h>
int main()
{
    int a;
    printf("输入:");
    scanf("%d",&a);
    if(a%2 == 0)
    {
	printf("为偶数\n");
    }
    else
    {
	printf("为奇数\n");
    }
    return 0;
}
