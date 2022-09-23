#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s1[32];
    char s2[32];
    char *p = s1;
    char *q = s2;
    printf("输入:\n");
    scanf("%s",s1);
    scanf("%s",s2);
    while (*p != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    printf("%s",s1);
    
    return 0;
}
