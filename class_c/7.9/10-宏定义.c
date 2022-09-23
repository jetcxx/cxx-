#include <stdio.h>
#define M 128
#define N 32

#define SUM M+N
#define SUM1 (M+N)

#define SUB(a,b) (a-b)

int main(int argc, const char *argv[])
{
	
	int i  = M + 5;
	printf("i = %d\n",i);
	int a = M + N;
	printf("a = %d\n",a);

	int b = SUM *10;  //   M + N *10 --->128 + 32 *10
	printf("b = %d\n",b);
	int c = SUM1 *10;  //   (M + N) *10 --->(128 + 32) *10
	printf("c = %d\n",c);

	int e = SUB(10,5) + 100;
	printf("e = %d\n",e);
	return 0;
}
