#include <stdio.h>
int main()
{
    int m = 0;
    int n = 0;
    for(m = 1; m <= 9;m++)
    {
	for(n = 1;n <= m; n++)
	{
	    printf("%d*%d=%d\t",m,n,m*n);
	}
    printf("\n");
    }
    return 0;
}

