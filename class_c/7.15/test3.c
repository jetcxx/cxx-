#include <stdio.h>
int main()
{
    int *a[4];
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int num4 = 40;
    a[0] = &num1;
    a[1] = &num2;
    a[2] = &num3;
    a[3] = &num4;
    int i;
    for(i = 0;i < 4;i++)
    {
	printf("%d ",*a[i]);
    }







    putchar(10);

    char *p[4];
    char s1[] = "helloworld";
    char s2[] = "play games";
    char s3[] = "woai nanjing";
    char s4[] = "woai beijing";

    p[0] = s1;
    p[1] = s2;
    p[2] = s3;
    p[3] = s4;
    for(i = 0;i < 4;i++)
    {
	printf("%s ",p[i]);
    }

    return 0;
}
