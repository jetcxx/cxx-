#include <stdio.h>
int main()
{
    int num,i;
    printf("输入:\n");
    scanf("%d",&num);
    int s[1000];
    int count = 0;
    int temp;
    temp = num;
    for(i = 0;i < num;i++)
    {
	s[i] = i + 1;
    }
    i = 0;
    while(num > 1)
    {
	if(s[i] != 0)
	{
	    count++;
	}
	if(count == 3)
	{
	    s[i] = 0;
	    count = 0;
	    num--;
	}
    	i++;
	 if(i == temp)
                {
                        i = 0;
                }
    }
    for(i = 0;i < temp;i++)
    {
	if(s[i] != 0)
	{
	    printf("%d\n",s[i]);
	}
    }
    return 0;
}
