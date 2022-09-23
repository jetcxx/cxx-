#include <stdio.h>
int main()
{
    int a,b,c;
    int i;
    for(i = 100;i < 1000;++i)
    {
	a = i/100;
	b = (i - a*100)/10;
	c = i % 10;
	if (i == a*a*a + b*b*b + c*c*c)
	    printf("%d\n",i);
    }
    return 0;
}

