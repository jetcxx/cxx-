#include <stdio.h>

void GetArray(int *arr,int length)
{
    int i = 0;
    printf("输入:");
    for(i = 0;i < length;i++)
    {
	scanf("%d",&arr[i]);
    }
}

void Sort(int *arr,int length)
{
    int i,j;
    for(i = 0;i < length - 1;i++)
    {
	for(j = 0;j < length - 1 - i;j++)
	{
	    if(arr[j] > arr[j + 1])
	    {
		int t = arr[j + 1];
		arr[j + 1] = arr[j];
		arr[j] = t;
	    }
	}
    }
}

void Print(int *arr,int length)
{
    int i;
    for(i = 0;i < length;i++)
    {
	printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[10] = {0};
    int length = sizeof(arr)/sizeof(int);
    GetArray(arr,length);
    Sort(arr,length);
    Print(arr,length);
    return 0;
}
