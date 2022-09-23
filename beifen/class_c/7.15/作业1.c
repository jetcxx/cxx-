#include <stdio.h>
#include <string.h>
int main()
{
    char str[32];
    printf("输入:\n");
    gets(str);
//    scanf("%s\n",str); //遇到空格停止，所以不能用scanf
    char *p = str;
   // p = str;
  //  int i = 0;
    int t = 0;
 /*   while(*p != '\0')
    {
	i++;
    }*/
    while(*p != '\0')
    {
	if(*p == ' ')
	{
	    t++;
	}
	p++;
    }
    printf("%d\n",t);
    return 0;
}
