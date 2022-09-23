#include <stdio.h>
#define WATERWIGHT (3.0e-23)
#define QUATERWIGHT 950
int main(int argc, const char *argv[])
{
	int num; //夸脱数
	double sum;
	printf("请输入水的夸脱数：\n");

	//从终端获取一个整数
	scanf("%d",&num);
	sum = QUATERWIGHT/WATERWIGHT * num;


	printf("%d 夸脱水中有%e个水分子\n",num,sum);
	return 0;
}
