#include <stdio.h>

int main(int argc, const char *argv[])
{
	int num;
	printf("请输入一个三位数：\n");
	scanf("%d",&num);
	printf("num = %d\n",num);

	int ge,shi,bai;
	ge = num %10;
	shi = num %100 /10;
	bai = num /100;
	int sum = ge +shi + bai;
	printf("%d 的各位相加的和为 %d\n",num,sum);
	return 0;
}
