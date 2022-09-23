#include <stdio.h>
int main(int argc, const char *argv[])
{
/*printf("%ld\n",sizeof(int *));
printf("%ld\n",sizeof(char *));
printf("%ld\n",sizeof(double *));
printf("%ld\n",sizeof(short *));
printf("%ld\n",sizeof(float *));*/
    int a = 1;
char ch = 'a';
int *pa = &a;
//int *pc = &ch;
char *pch = &ch;
ch = 'b';
*pch = 'c';
printf("ch = %c,%c\n",ch,*pch);
printf("%p\n",pa);
printf("%p\n",pch);
printf("%p\n",pa + 1);
printf("%p\n",pch + 1);
return 0;
}
