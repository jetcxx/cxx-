#include <stdio.h>
int main(void)
{
    int a,m,s;
    for (a = 1;a < 1000;a++)
    {
	s = 0;
	for(m = 1;m < a;m++)
	    if(a%m == 0)
		s += m;
	if(s == a)
	    printf("%d\n",a);
    }
    return 0;
}
