#include <stdio.h>
int main()
{
/*    char buf[32];
    printf("输入字符串:");
    scanf("%s",buf);
    printf("输出字符串:%s",buf);
    return 0;
*/
    char buf[32];
	scanf("%[^\n]",buf);//到换行符结束
	printf("buf = %s\n",buf);
}

