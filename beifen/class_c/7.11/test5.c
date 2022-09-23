#include"stdio.h"
int main()
{
int a,b,c;
printf("一千以内的完数有:\n");
for(a=1;a<1000;a++)
  {
	b=0;
for(c=1;c<a;c++)
	if(a%c==0)
	b+=c;
	if(b==a)
	printf("%d  ",a);
}
return 0;
}   

