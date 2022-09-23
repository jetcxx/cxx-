#include <stdio.h>
int main()
{
    int m,n,row;
    printf("输入行数:");
    scanf("%d",&row);
    for (m = 1;m <= row; ++m)
    {
	for (n = 1;n <= m;++n)
	{
	    printf("* ");
	}
    printf("\n");
    }
    return 0;
}
