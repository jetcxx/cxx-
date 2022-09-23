#include <stdio.h>
#include <math.h>
int main()
{
    float x1,x2,a,b,c,d;
    printf("输入三个系数:\n");
    scanf("%f %f %f",&a,&b,&c);
    d = b*b-4*a*c;
    x1 = (-b + d)/(2*a);
    x2 = (-b - d)/(2*a);
    printf("x1 = %f\nx2 = %f\n",x1,x2);
    return 0;
}
