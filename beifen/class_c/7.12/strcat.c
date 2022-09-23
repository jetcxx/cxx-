#include <stdio.h>
#include <string.h>
int main()
{
    char s1[32] = "helloworld";
    char s2[32] = "abcde";
    strcpy(s1,s2);
   // strcat(s1,s2);
    printf("%s\n",s1);
    return 0;
}
