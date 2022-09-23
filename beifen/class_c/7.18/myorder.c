#include <stdio.h>

void myorder(int *arr,int len)
{
    int i;
    for(i = 0;i < len;i++)
    {
	printf("%d ",arr[i]);
    }
    putchar(10);
}

int main()
{
    int arr[9] = {10,20,30,40,50,60,70,80,90};
    int len = sizeof(arr)/sizeof(int);
    myorder(arr,len);
    return 0;
}
