#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i,j;
    int s[10] = {0};
    printf("输入:\n");
    for(i = 0;i < 10;i++)
    {
        scanf("%d",&s[i]);
    }
    for(i = 0;i < 10;i++)
    {
        for(j = 0;j < 10 - i;j++)
        {
            if(s[j] > s[j+1])
            {
                int t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
    for(i = 0;i < 10;i++)
    {
        printf("%d ",s[i]);
    }
    return 0;
}
