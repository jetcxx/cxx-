#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
int a[] = {10,20,30,40,50,60,70,80,90};
printf("sizeof(a) = %ld\n",sizeof(a));
printf("%ld",strlen(a));
return 0;
}
