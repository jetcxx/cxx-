#include <stdio.h>
typedef union aa{
unsigned char a;
int c;
}aa_t;
aa_t a;
int main(int argc, const char *argv[])
{
a.c = 0x12345678;
if(a.a == 0x12)
{
printf("这是大端的机器\n");
}
else if(a.a == 0x78)
{
printf("这是小端机器\n");
}
return 0;
}
