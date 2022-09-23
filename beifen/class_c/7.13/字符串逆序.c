#include <stdio.h>
int main()
{
    char s[32] = {0};
    printf("输入:\n");
    scanf("%s",s);
    int i = 0;
    int l = 0;
    while(s[i] != 0)
	{
	    i++;
	    l++;
	}
    char t;
    int x = 0;
    int y = l - 1;
    for (i = 0;i < l/2;i++)
    {
	t = s[x];
	s[x] = s[y];
	s[y] = t;
	x++;
	y--;
    }
    printf("%s\n",s);
    return 0;
}
