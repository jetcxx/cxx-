#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s1[32];
    char *p = s1;
    printf("输入:\n");
    scanf("%s",s1);
    int i = 0;
    while(*p != '\0')
    {
        i++;
        p++;
    }
    printf("%d",i);
    return 0;
}
