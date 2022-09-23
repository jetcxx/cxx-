#include <stdio.h>

int main(int argc, const char *argv[])
{
	float a = 345641.12345;
	printf("a = %f\n",a);
	printf("a = %e\n",a);

	float b = -1.78e-5;
	printf("b = %f %e\n",b,b);
	return 0;
}
