#include <stdio.h>
int main()
{
    char ch = 'a';
    char *pch = &ch;
    ch = 'b';
    *pch = 'c';
    printf("%c,%c",ch,*pch);
    return 0;
}
