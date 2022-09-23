#include <stdio.h>
int main()
{
    char str[] = "1234";
    char *p;
    int a;
    p = str;
    while(*p != 0)
    {
	a = *p;
	*p++;
    }
    printf("%d",a);
    return 0;
}
	
