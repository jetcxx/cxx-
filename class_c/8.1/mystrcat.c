#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s1[32] = "helloworld";
    char s2[32] = "123456789";
    char *p = s1;
    char *q = s2;
    while(*p != '\0')
    {
        p++;
    }
    while(*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    printf("%s\n",s1);
    return 0;
}
