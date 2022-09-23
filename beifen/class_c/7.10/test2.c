#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 100,b = 20,c;
	c = (++a,++b,a = a+b,a++);
	printf("a = %d,b = %d,c = %d\n",a,b,c);
	return 0;
}
