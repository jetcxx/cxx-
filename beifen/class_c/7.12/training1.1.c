#include <stdio.h>
int main()
{
    int a,b;
    b = a%10;
    printf("输入:\n");
    scanf("%d",&a);
    if(b < 9)
    {
	int c = b/10;
	printf("%d",c);
    }
    else
    {
	int d = b/10 + 1;
	printf("%d",d);
    }
    return 0;
}



    
