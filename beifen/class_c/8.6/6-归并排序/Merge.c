#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void Merge(int *a,int start,int mid,int end)
{
    int Left_len = mid - start + 1;
    int Right_len = end - mid;
    int *L = (int *)malloc(sizeof(int) *Left_len);
    int *R = (int *)malloc(sizeof(int) *Right_len);
    int i,j,k;
    for(i = 0,k = start;i < Left_len;i++,k++)
    {
        L[i] = a[k];
    }
    for(j = 0;j < Right_len;j++,k++)
    {
        R[j] = a[k];
    }
    for(i = 0,j = 0,k = start;i < Left_len && j < Right_len;k++)
    {
        if(L[i] < R[j])
        {
            a[k] = L[i++];
        }
        else
        {
            a[k] = R[j++];
        }
        
    }
    if(j < Right_len)
    {
        for(;j < Right_len;j++,k++)
        {
            a[k] = R[j];
        }
    }
    if(i < Left_len)
    {
        for(;i < Left_len;i++,k++)
        {
            a[k] = L[i];
        }
    }
    free(L);
    free(R);
}

void MergeSort(int *a,int start,int end)
{
    if(start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    MergeSort(a,start,mid);
    MergeSort(a,mid + 1,end);
    Merge(a,start,mid,end);
}

int main(int argc, char const *argv[])
{
    int i;
    int array[10000] = {0};
    srand(time(NULL));
    for(i = 0;i < 10000;i++)
    {
        array[i] = rand() % 1000;
    }
    int length = sizeof(array)/sizeof(int);
    MergeSort(array,0,length - 1);
    for ( i = 0; i < length; i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
    return 0;
}
