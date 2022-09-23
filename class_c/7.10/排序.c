#include <stdio.h>
int main()
{
    int a,b,c;
    printf("输入三个数:");
    scanf("%d %d %d",&a,&b,&c);
    printf("排序前顺序为:%d %d %d",a,b,c);
    int i;
    if (a > b)
    {
	i = a;
	a = b;
	b = i;
    }
    if (a > c)
    {
	i = a;
	a = c;
	c = i;
    }
    if (b > c)
    {
	i = b;
	b = c;
	c = i;
    }
    printf("交换后顺序为:%d %d %d",a,b,c);
    return 0;
}
