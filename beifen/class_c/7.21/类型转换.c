#include <stdio.h>
int main(int argc, const char *argv[])
{
float a = 3.14;
int b =a;
printf("b = %d\n",b);

int i = -20;
unsigned int j = 6;
if(i + j > 0)
{
printf("i + j > 0\n");
}
else
{
printf("i+ j < 0\n");
}

int m = 10,n = 4;
printf("%d\n",m/n);
printf("%f\n",(float)(m/n));
printf("%f\n",(float)m/(float)n);

return 0;
}
