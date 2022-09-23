#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i;
	char a;
	for(i = 0; i < 255;i++)
	{
		a += 1;
		printf("%d ",a);
	}
	printf("\n");
	return 0;
}
