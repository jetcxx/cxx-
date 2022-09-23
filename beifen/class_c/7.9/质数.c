#include <stdio.h>
int main()
{
    int a , i;
    int n = 0;
    for(a = 2;a <= 100;a++)
    {
	for(i = 2;i <= a;i++)
	{
	    if(a%i == 0)
		break;
	}
		if(i == a && n < 4)
		    {
   			printf("%d\t",a);
   			n++;
		}
		if(i == a && n >= 4)
		{
		    printf("\n%d\t",a);
		    n = 0;
		    n++;
	  //  printf("%d",a);
	
    }}
    return 0;
}
	


