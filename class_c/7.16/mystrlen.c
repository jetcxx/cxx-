#include <stdio.h>

long mystrlen(const char *s)
{
    int i = 0;
    while(*s != '\0')
    {
	i++;
	s++;
    }
    return i;
}

int main()
{
    char a[32] = {0};
    printf("输入:\n");
    gets(a);
    int ret = mystrlen(a);
    printf("%d\n",ret);
    return 0;
}
