#include <stdio.h>
int main()
{
    double a,b,c;
    printf("输入三个数，以空格分开:");
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a >= b && a >= c)
    {
	printf("最大数是%lf\n",a);
    }
    if(b >= a && b >= c)
    {
	printf("最大数是%lf\n",b);
    }
    if(c >= a && c >= b)
    {
	printf("最大数是%lf\n",c);
    }
    return 0;
}
