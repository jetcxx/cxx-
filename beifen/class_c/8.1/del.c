#include <stdio.h>
int main(int argc, char const *argv[])
{
    int pos = 0;
    printf("输入:\n");
    scanf("%d",&pos);
    char s[32] = "helloworld";
    int i = 0;
    for(i = 0;i < 32;i++)
    {
        if(i == pos)
        {
            for(i = pos-1;i < 32;i++)
            {
                s[i] = s[i+1];
            }
        }
    }
    printf("%s\n",s);
    return 0;
}
