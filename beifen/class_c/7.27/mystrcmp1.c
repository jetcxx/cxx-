#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s1[32];
    char s2[32];
    //char *p = s1;
    //char *q = s2;
    scanf("%s",s1);
    scanf("%s",s2);
    int i;
    //while(*p != '\0' || *q != '\0')
    for(i = 0;s1[i] != '\0' || s2[i] != '\0';i++)
    {
        if(s1[i] == s2[i])
        {
            return 0;
        }
        if(s1[i] > s2[i])
        {
            return 1;
        }
        else
        {
            return -1;
        }
        
        

    }
    return 0;
}
