#include <stdio.h>
int main()
{
    char s1[] = "hello world";
    char s2[] = "hello world";
    printf("s1 = %p,s2 = %p\n",s1,s2);

    s1[6] = '8';
    printf("s1 = %s\n",s1);


    char *p1 = "hello world";
    char *p2 = "hello world";
    printf("p1 = %p,p2 = %p\n",p1,p2);


    p1 = "nihao nanjing";
    printf("p1 = %p,p1 = %s\n",p1,p1);



    return 0;
}
