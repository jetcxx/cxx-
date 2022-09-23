#include <stdio.h>
int main()
{
    char a;
    printf("输入一个字符:");
    scanf("%c",&a);
    if (a >= 'a' && a <= 'z' || a >='A' && a <= 'Z')
	printf("%c是字母",a);
    else
	printf("%c不是字母",a);
    return 0;
}
