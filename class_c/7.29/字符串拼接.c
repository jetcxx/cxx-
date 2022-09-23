#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s1[32] = "helloworld";
    char s2[32] = "123456789";
    char s3[32] = {0};
    scanf("%s",s3);
    char *p = s1;
    char *q = s2;
    char *t = s3;
    while (*p != '\0')
    {
        p++;
    }
    while(*t != '\0')
    {
        *p = *t;
        p++;
        t++;
    }
    while(*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    printf("%s",s1);
    putchar(10);
    return 0;
}
