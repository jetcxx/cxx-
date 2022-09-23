#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    int i;
    int j = 0;
    for(i = a;i <= b;i++)
    {
        j += i;
    }
    printf("%d\n",j);
    return 0;
}
