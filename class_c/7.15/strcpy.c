#include <stdio.h>
int main()
{
    char s1[] = "helloworld";
    char s2[] = "123456789";
    char *p = s1;
    char *q = s2;
    int i = 0;
    while(*q != '\0')
    {
	*p = *q;
	p++;
	q++;
    }
    *p = *q;
    printf("%s\n",s1);
    return 0;
}
