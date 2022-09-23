#include <stdio.h>
int main(int argc, char const *argv[])
{
    /*int a = 0;
    scanf("%d",&a);
    printf("%d",a%10);
    printf("%d",a/10%10);
    printf("%d",a/100%10);*/
    int num;
    printf("输入:\n");
    scanf("%d",&num);
    int reverse = 0;
    while (num != 0)
    {
        reverse = reverse *10 +num%10;
        num /= 10;
    }
    printf("%d\n",reverse);
    
    return 0;
}
