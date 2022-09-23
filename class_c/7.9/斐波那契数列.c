#include <stdio.h>
int main()
{
    int a,i,t1 = 0,t2 = 1,next;
    printf("输出多少个:");
    scanf("%d",&a);
    printf("数列为:");
    for(i = 1;i <= a;++i)
    {
	printf("%d, ",t1);
	next = t1 + t2;
	t1 = t2;
	t2 = next;
    }
    return 0;
}
