#include <stdio.h>
int main()
{
    double firstnum,secondnum,finalnum;
	printf("输入第一个数:");
	scanf("%lf",&firstnum);
	printf("输入第二个数:");
	scanf("%lf",&secondnum);
    finalnum = firstnum;
    firstnum = secondnum;
    secondnum = finalnum;
    printf("交换后第一个数:%lf\n交换后第二个数:%lf\n",firstnum,secondnum);
    return 0;
}
