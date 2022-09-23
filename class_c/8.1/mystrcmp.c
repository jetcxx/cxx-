#include <stdio.h>
int mystrcmp(char *s1,char *s2);
int main(int argc, char const *argv[])
{
    char s1[32] = "helloworld";
    char s2[32] = "123456789";
    int value;
    value = mystrcmp(s1,s2);
    printf("%d",value);
    return 0;
}

int mystrcmp(char *s1,char *s2)
{

    //char *p = s1;
    //char *q = s2;
    int i = 0;
    for(i = 0;s1[i] != '\0' || s2[i] != '\0';i++)
    {
        if(s1[i] == s2[i])
        continue;
        else
        {
            return s1[i] > s2[i]?1:(-1);
        }
        
    }
    return 0;
}
