#include <stdio.h>
int main()
{
    puts("hello world");
    char s[32] = "nihao world";
    puts(s);
    char buf[32];
    gets(buf);
    puts(buf);

    puts("");
    putchar(10);
    putchar('\n');
    return 0;
}

