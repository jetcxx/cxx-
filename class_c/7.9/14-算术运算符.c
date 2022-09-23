#include <stdio.h>

int main(int argc, const char *argv[])
{
	float m = 12.67,n = 12.89;
	printf("%f + %f = %f\n",m,n,m+n);
	printf("%f - %f = %f\n",m,n,m-n);
	printf("%f * %f = %f\n",m,n,m*n);
	printf("%f / %f = %f\n",m,n,m/n);

	//取余只能用于两个整数之间，浮点数据不能取余
	//printf("%f %% %f = %f\n",m,n,m % n);
	
	printf("************************\n");
	int i = 100;
	printf("i = %d\n",i);

	int num = i++;  //i = i +1
	printf("num = %d,i = %d\n",num,i);


	int num1 = ++i;
	i+1;
	printf("num1 = %d,i = %d\n",num1,i);
	int a = 2,b = 3;
	int num2 = a+++b;
	printf("num2 = %d,a =%d,b = %d\n",num2,a,b);
	int j = 100;
	//最终j值不一定是多少，编译器不一样，最终结果也不一样
	int num3 = ++j + ++j+ ++j; //204+103
	printf("num3 = %d\n",num3);
	return 0;
}
