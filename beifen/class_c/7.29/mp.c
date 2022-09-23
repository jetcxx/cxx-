#include <stdio.h>
int main(int argc, char const *argv[])
{
    int s[10] = {0};
    int i,j;
    int len = sizeof(s)/sizeof(int);
    for(i = 0;i < len;i++)
    {
        scanf("%d",&s[i]);
    }   
    for(i = 0;i < len - 1;i++)
    {
        for(j = 0;j < len - 1 - i;j++)
        {
            int t;
            if(s[j] < s[j + 1])
            {
                t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
    for(i = 0;i < len;i++)
    {
        printf("%d",s[i]);
    }
    return 0;
}
