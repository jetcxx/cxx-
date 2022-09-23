#include <stdio.h>
int main()
{
int a[][4] = {10,20,30,40,50,60,70,80,90};
printf("sizeof(a) = %ld\n",sizeof(a));
int i,j;
for(i = 0; i < 3;i++)//行数
{
for(j = 0; j < 4;j++)//列数
{
printf("%d ",a[i][j]);
}
printf("\n");
}
return 0;
}
