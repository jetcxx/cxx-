#include <stdio.h>

char func(char ch)
{
    int i;
    int n = 0;
    for(i = 0;i < 8;i++)
    {
	if((ch>>i)&1 == 1)
	{
	    n++;
	}
    }
    return n;
}


int main()
{
    char ch;
    scanf("%c",&ch);
    int n = func(ch);
    printf("%d\n",n);
    return 0;
}
