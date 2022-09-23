#include <stdio.h>
int main(int argc, const char *argv[])
{
	int i; //未初始化
	i = 100; //赋值
	int a = 100;  //定义的同时并且赋值：初始化
	a = 999;
	printf("a = %d\n",a);
	return 0;
}
