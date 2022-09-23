#include <stdio.h>
int main()
{
    char str[32];
    printf("输入:\n");
    gets(str);
    char *p = str;
    while(*p != '\0')
    {
	if((*p >= 65) && (*p <= 90))
	{
	    *p = *p + 32;
	    goto inc;
	}
	if((*p >= 97) && (*p <= 122))
	{
	    *p = *p - 32;
	    goto inc;
	}
	if((*p >= 48) && (*p <= 57))
	{
	    *p = '.';
	    goto inc;
	}
	else
	{
	    *p = '*';
	    goto inc;
	}
	inc:p++;
    }
    printf("%s",str);
    return 0;
}
