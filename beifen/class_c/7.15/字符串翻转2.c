#include <stdio.h>
#include <string.h>

int main()
{
    char str[32];
    char *p = NULL, *q = NULL;
    printf("输入:\n");
    scanf("%s",str);
    p = &str[0];
    q = &str[strlen(str) - 1];
    char t;
    while(p < q)
    {
	t = *q;
	*q = *p;
	*p = t;
	p++;
	q--;
    }
    printf("%s",str);
    return 0;
}

