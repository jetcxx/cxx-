#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s[] = "helloworld";
    int a;
    printf("输入:\n");
    scanf("%d",&a);
    int i = 0;
    for(i = 0;i < strlen(s);i++)
    {
        if(i = a)
        {
            for(i = a-1;i < strlen(s);i++)
            {
                s[i] = s[i+1];
            }
        }
    }
    printf("%s\n",s);
    return 0;
}

