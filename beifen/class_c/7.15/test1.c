#include <stdio.h>
int main(int argc, const char *argv[])
{
int a[3][4] ={10,20,30,40,50,60,70,80,90,100,110,120};
printf("a = %p\n",a);
printf("a = %p\n",a + 1);
printf("*a = %p\n",*a);
printf("*a +1 = %p\n",*a + 1);
printf("**a = %d\n",**a);
printf("*(*a+1) = %d\n",*(*a+1));

int i,j;
for(i = 0;i < 3;i++)
{
    for(j = 0;j < 4;j++)
    {
	printf("%d ",*((*a + i)+j));
    }
}

return 0;
}
