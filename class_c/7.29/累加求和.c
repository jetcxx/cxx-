#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a,b;
    printf("输入:\n");
    scanf("%d %d",&a,&b);
    int i;
    int j = 0;
    for(i = a;i <= b;i++)
    {
        j += a;
        a++;
    }
    printf("%d",j);
    return 0;
}
