#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s[32] = "helloworld";
    char *p = s;
    int i = 0;
    while(*p != '\0')
    {
        i++;
        p++;
    }
    printf("%d\n",i);
    return 0;
}
