#include <stdio.h>
int main()
{
    char ch[] = "helloworld";
    char *pch = &ch[0];
    char *qch = &ch[10];
    int i = 0,j = 0;
    while (i < 5)
    {
	char t = *pch;
	*pch = *qch;
	*qch = t;
	pch++;
	qch--;
	i++;
    }
    for(j = 0;j < 11;j++)
    {
	printf("%c",ch[j]);
    }
    return 0;
}
