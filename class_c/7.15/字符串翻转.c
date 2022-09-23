#include <stdio.h>
#include <string.h>

int main()
{
    char str[32];
    printf("输入:\n");
    scanf("%s",str);
    char *p = NULL, *q = NULL;
    char t;
    for(p = &str[0],q = &str[strlen(str) - 1];p < q;p++,q--)
    {
	t = *p;
	*p = *q;
	*q = t;
    }
    printf("%s",str);
    return 0;
}
