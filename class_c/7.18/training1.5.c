#include <stdio.h>

int main()
{
    int a,i,s;
    for(a = 1;a < 10000;a++)
    {
	s = 0;
	for(i = 1;i < a;i++)
	{
	    if(a%i == 0)
	    {
		s += i;
	    }
	}
	if(s == a)
	{
	    printf("%d ",a);
	}
    }
    return 0;
}
