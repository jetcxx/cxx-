#include <stdio.h>
int main()
{
    int a[9] = {12,41,53,64,32,19,86,45,37};
    int i,j;
    int length = sizeof(a)/sizeof(int);
    for (i = 0;i < length-1;i++)
	for (j = 0;j < length-1;j++)
	{
	    if(a[j] < a[j + 1])
		break;
	}
    printf("%d\n%p\n",a[i],a[i]);
    return 0;
}
