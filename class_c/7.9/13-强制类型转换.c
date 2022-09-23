#include <stdio.h>

int main(int argc, const char *argv[])
{
	//隐式类型转换默认一般从地精度往高精度转换
	float a = 3.14;
	int b = a;
	printf("b = %d\n",b);

	int i = -20;
	unsigned int j = 7;
	if(i + j > 0)
	{
		printf("i + j > 0\n");
	}
	else
	{
		printf("i+ j < 0\n");
	}

	//显示调用，强制类型转换
	int m = 10,n = 4;
	printf("%d\n",m/n);

	printf("%f\n",(float)(m/n));
	printf("%f\n",(float)m/(float)n);

	int num = 0xaabbccdd;
	char ch = (char)num;
	printf("ch = %#x\n",ch);
	return 0;
}
