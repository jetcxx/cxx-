#include <stdio.h>
#include <string.h>
int main()
{
    char s[32] = {0};
    int i,p;
    char j;
    printf("输入字符串，插入位置，插入内容:\n");
    scanf("%s%d %c",s,&p,&j);
    int l = strlen(s);
    for(i = 0;i < l - p + 1;i++)
    {
	s[l - i] = s[l - i - 1];
    }
    s[p - 1] = j;
    printf("%s\n",s);
    return 0;
}

