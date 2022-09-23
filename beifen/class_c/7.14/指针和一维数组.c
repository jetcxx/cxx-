#include <stdio.h>
int main()
{
    int a[5] = {1,2,3,4,5};
    int *p = a;

    int i = 0;
    for(i = 0;i < 5;i++)
    {
	printf("%d",*(p + i));
    }
    putchar(10);

    char *s = "helloworld";
    printf("%s\n",s);
    for(i = 0;i < 10;i++)
    {
	printf("%c",*(s + i));
    }
    putchar(10);
    return 0;
}
