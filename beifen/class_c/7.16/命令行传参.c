#include <stdio.h>
int main(int argc,const char *argv[])
{
    printf("argc = %d\n",argc);

    int i = 0;
    for(i = 0;i < argc;i++)
    {
	printf("argv[%d] = %s\n",i,argv[i]);
    }
    return 0;
}
