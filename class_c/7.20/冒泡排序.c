#include <stdio.h>

void GetArray(int a[],int length)
{
    int i;
    printf("输入:\n");
    for(i = 0;i < length;i++)
    {
	scanf("%d",&a[i]);
    }
}

void sort(int *a,int length)
{
    int i,j;
    for(i = 0;i < length - 1;i++)
    {
	for(j = 0;j < length -1 - i;j++)
	{
	    if(a[j] > a[j + 1])
	    {
		int t = a[j + 1];
		a[j + 1] = a[j];
		a[j] = t;
	    }
	}
    }
}

void print(int *a,int length)
{
    int i;
    for(i = 0;i < length;i++)
    {
	printf("%d ",a[i]);
    }
    printf("\n");
}
    

int main()
{
    int a[10] = {0};
    int length = sizeof(a)/sizeof(int);
    GetArray(a,length);
    sort(a,length);
    print(a,length);
    return 0;
}
