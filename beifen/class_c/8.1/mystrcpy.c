#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s1[32] = "helloworld438273428327";
    char s2[32] = "123456789";
    char *p = s1;
    char *q = s2;
    while(*p != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    printf("%s",s1);
    return 0;
}
