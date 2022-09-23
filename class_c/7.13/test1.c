#include <stdio.h>
int main(int argc, const char *argv[])
{
//int a[2][3] ={{1,2,3},{4,5,6}};
//int a[2][3] = {{1},{4,5}};
//int a[][3] ={{1,2,3},{4,5,6}};
//int a[][3] ={1,2,3,4,5,6};//按列存储
//int a[2][] ={{1,2,3},{4,5,6}};//错误写法
int a[2][3] = {0};
int i,j;
for(i = 0; i < 2;i++)
{
for(j = 0; j < 3;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
printf("%p\n",&a[0][0]);
printf("%p\n",a[0]);//表示数组首行首元素的地址，a[1]第二行首元素的地址
printf("%p\n",a);//a表示首行地址
printf("%p\n",&a);//&a表示整个数组的地址
printf("***********************\n");
printf("%p\n",&a[0][0] + 1);
printf("%p\n",a[0] + 1);
printf("%p\n",a + 1);
printf("%p\n",&a + 1);
return 0;
}
