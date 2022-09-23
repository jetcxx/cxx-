#include <stdio.h>
int main()
{
    char a,lvowels,cvowels;
    printf("输入一个字母:");
    scanf("%c",&a);
    lvowels = (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    cvowels = (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
    if (lvowels || cvowels)
	printf("是元音");
    else
	printf("是辅音");
    return 0;
}

