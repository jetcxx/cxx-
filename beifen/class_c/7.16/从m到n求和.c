#include <stdio.h>
int sum(int m,int n);

int main()
{
    int begin,end;
    printf("输入:\n");
    scanf("%d %d",&begin,&end);
    int result = sum(begin,end);
    printf("%d\n",result);
    return 0;
}
int sum(int m,int n)
{
    int i;
    int s = 0;
    for(i = m;i <= n;i++)
    {
	s += i; 
    }
    return s;
}
