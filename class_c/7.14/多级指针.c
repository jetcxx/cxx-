#include <stdio.h>
int main()
{
    int a = 100;
    int *p = &a;
    int **q = &p;
    int ***w = &q;

    printf("a = %d %d %d %d\n",a,*p,**q,***w);
    printf("p = %p %p %p %p\n",&a,p,*q,**w);
    printf("q = %p %p %p\n",&p,q,*w);
    printf("w = %p %p\n",&q,w);




    return 0;
}
