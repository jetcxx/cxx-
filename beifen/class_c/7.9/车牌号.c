#include <stdio.h>
int main()
{
    int a;
    int i;
    int b,c,d,e;
    for (a = 1000;a < 10000;a++)
    {
	for(i = 1;i < 100;i++)
	{
	if (i * i == a)
	{
	    b = a / 1000;
	    c = (a - b * 1000)/ 100;
	    d = (a - b * 1000 - c * 100)/ 10;
	    e = a % 10;
	    if (b == c && d == e)
		printf("%d\n",a);
	}
    }
    }
    return 0;
}
