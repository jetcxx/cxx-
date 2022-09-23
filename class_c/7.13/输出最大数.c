#include <stdio.h>
int main()
{
    int a[] = {24,89,12,99,26,43,87,54,75,23,56,17};
    int i;
    int max = a[0];
    int pos = 0;
    for (i = 1;i < sizeof(a)/sizeof(int);i++)
    {
	if(max < a[i])
	{
	    max = a[i];
	    pos = i;
	}
    }
    printf("max = %d,pos =  %d\n",max,pos);
    return 0;
}
