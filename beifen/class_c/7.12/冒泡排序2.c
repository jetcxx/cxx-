#include <stdio.h>
int main()
{
    int s[8] = {0};
    int i,j;
    printf("输入:\n");
    for(i = 0 ; i < sizeof(s)/sizeof(int);i++)
	{
	scanf("%d",&s[i]);
	}
 //   char s[8] = {32,14,56,34,89,14,36,24};
    for (i = 0;i < sizeof(s)/sizeof(int);i++)
    {
	for(j = 0;j < sizeof(s)/sizeof(int) - i;j++)
	    if(s[j] > s[j + 1])
	    {
		int t = s[j];
		s[j] = s[j + 1];
		s[j + 1] = t;
	    }
    }

    for(i = 0; i < sizeof(s)/sizeof(int);i++)
{
printf("%d ",s[i]);
}
  //  printf("%d",s[i]);
    return 0;
}

		

