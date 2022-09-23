#include <stdio.h>
int main()
{
    int n;
    printf("输入:\n");
    scanf("%d",&n);
    int a = n/10;
    if(n%10 < 9)
    {
	printf("%d\n",a);
    }
    else
    {
	printf("%d\n",a + 1);
    }
    return 0;
}

