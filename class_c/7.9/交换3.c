#include <stdio.h>
int main()
{
    int firstnum,secondnum;
    printf("输入第一个数:");
    scanf("%d",&firstnum);
    printf("输入第二个数:");
    scanf("%d",&secondnum);
    firstnum = firstnum ^ secondnum;
    secondnum = firstnum ^ secondnum;
    firstnum = firstnum ^ secondnum;
    printf("交换后第一个数:%d\n交换后第二个数:%d\n",firstnum,secondnum);
    return 0 ;
}

