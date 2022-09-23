#include <stdio.h>

void ArrayOrder(int (*a)[4])
{
    int i,j;
    for(i = 0;i < 3;i++)
    {
	for(j = 0;j < 4;j++)
	{
	    printf("%-5d",a[i][j]);
	}
	putchar(10);
    }
}
int main(int argc,const char *argv[])
{
    int arr[3][4] = {10,20,30,40,50,60,70,80,90,100,110,120};
    ArrayOrder(arr);
    return 0;
}
