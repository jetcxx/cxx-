#include <stdio.h>

int swap(int *i,int *j)
{
    int t = *i;
    *i = *j;
    *j = t;
   // return i,j;
}

int main()
{
    int a,b;
    printf("输入:\n");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("%d %d\n",a,b);
    return 0;
}
