#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a;
    int tmp = 0;
    scanf("%d",&a);
    while(a != '\0')
    {
        tmp = a%10 + tmp*10;
        a /= 10;
    }
    printf("%d\n",tmp);
    return 0;
}
