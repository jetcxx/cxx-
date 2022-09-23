#include <stdio.h>
struct aa{
char a;
union{
int b;
char c;
};
};
int main(int argc, const char *argv[])
{
struct aa a;
a.a = 10;
a.b = 0xaa;
printf("sizeof(aa) = %ld\n",sizeof(a));
printf("c = %#x\n",a.c);
return 0;
}
