#include <stdio.h>

int main(int argc, const char *argv[])
{
	int num = 1000;
	printf("num = %d\n",num);
	//输出八进制数,#:表示输出前导符
	printf("num = %#o\n",num);
	//输出十六进制数
	printf("num = %#x\n",num);

	int a = 0756;
	int b = 0xabcdef;
	int c = 0b10011100;  //定义一个二进制常量
	printf("a = %d,%#o,%#x\n",a,a,a);
	printf("b = %d,%#o,%#x\n",b,b,b);
	printf("c = %d,%#o,%#x\n",c,c,c);
	return 0;
}
