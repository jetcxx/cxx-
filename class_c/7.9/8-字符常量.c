#include <stdio.h>

int main(int argc, const char *argv[])
{
	char a = 'w';
	printf("a = %d, %c\n",a,a);


	char b = 97;
	printf("b = %d, %c\n",b,b);
	
	char c = 'w';
	c = c - 32;
	printf("c = %c ,%d\n",c);
	return 0;
}
