#include <stdio.h>
int main(int argc, const char *argv[])
{
int a[4];
int i;
a[0] = 222;
a[1] = 333;
a[2] = 444;
a[3] = 555;
for(i = 0; i < 4;i++)
{
printf("a[%d] = %d\n",i,a[i]);
}
printf("sizeof(a) = %ld\n",sizeof(a));
printf("%p\n",&a[0]);
printf("%p\n",a);
printf("%p\n",&a);
printf("**********************\n");
printf("%p\n",&a[0] + 1);
printf("%p\n",a + 1);
printf("%p\n",&a + 1);
return 0;
}
