#include <stdio.h>
typedef union aa{
char a;
short b;
int c;
}aa_t;
aa_t a;
int main(int argc, const char *argv[])
{
a.a = 10;
a.b = 90;
a.c = 0xaabbccdd;
printf("a = %#x,b = %#x,c =%#x\n",a.a,a.b,a.c);
return 0;
}
