#include <stdio.h>
static int ww = 1000;
    static int add(int a,int b)
    {
	return a+b;
    }

int main()
{
    int ww;
    int add(int,int);
    ww = 2000;
    printf("ww = %d\n",ww);
    printf("add = %d\n",add(100,200));
    return 0;
}
