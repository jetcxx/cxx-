#include <stdio.h>
int main()
{
    int a,b,i,m,n;
    a = 40;
    b = 200;
    i = 1.1;
    n =  m*i*b;
    m = 1;
    while (m*a < n)
    {
	m++;
    }
	printf("要%d年",m);
    return 0;
}

