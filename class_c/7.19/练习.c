#include <stdio.h>


void fun(int a,int p1,int p2)
{
    int i;
    if(p1 > p2)
    {
	int t = p1;
	p1 = p2;
	p2 = t;
    }
    for(i = p2;i >= p1;i--)
    {
	int t = 0;
	t = (a >> (i - 1)) & 1;
	if(t == 1)
	{
	    printf("1");
	}
	else
	{
	    printf("0");
	}
    }
    for(i = 0;i < 32;i++)
    {

}


int main()
{
    int a,p1,p2;
    scanf("%d %d %d",&a,&p1,&p2);
    fun(a,p1,p2);
    return 0;
}
