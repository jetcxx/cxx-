#include <stdio.h>
int main()
{
    double firstnum,secondnum;
    printf("输入第一个数:");
    scanf("%lf",&firstnum);
    printf("输入第二个数:");
    scanf("%lf",&secondnum);
    firstnum = firstnum + secondnum;
    secondnum = firstnum - secondnum;
    firstnum = firstnum - secondnum;
    printf("第一个数为:%lf\n第二个数为:%lf\n",firstnum,secondnum);
    return 0;
}

