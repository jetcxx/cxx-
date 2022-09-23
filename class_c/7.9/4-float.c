#include <stdio.h>

int main(int argc, const char *argv[])
{
	//%f:输出4字节的float
	//float类型默认保留小数点后6位，并且会四舍五入
	float a = 3.141592653456;
	printf("a = %f\n",a);
	float b = 5.6;
	printf("b = %f\n",b);
	
	//注意：如果一个浮点型数据非常大，末尾小数点可能会丢失精度
	float c = 123456789.456487;
	printf("c = %f\n",c);

	double d = 24.456789123;
	printf("d = %lf\n",d);
	return 0;
}
