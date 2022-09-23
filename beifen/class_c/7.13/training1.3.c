#include <stdio.h>
int main()
{
    double a[5];
    int i,j,t;
    printf("输入:\n");
    for(i = 0;i < sizeof(a)/sizeof(double);i++)
    {
	scanf("%lf",&a[i]);
    }
    for(i = 0;i < sizeof(a)/sizeof(double) - 1;i++)
    {
	for(j = 0;j < sizeof(a)/sizeof(double) - 1 -i;j++)
	{
	    if(a[j] > a[j + 1])
	    {
		t = a[j + 1];
		a[j + 1] =a[j];
		a[j] = t;
	    }
	}
    }
    for(i = 0;i < sizeof(a)/sizeof(double);i++)
    {
	printf("%.2lf\n",a[i]);
    }
    return 0;
}
