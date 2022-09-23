#include <stdio.h>
int main()
{
    char ch1[32] = "helloworld";
    char ch2[32] = "123456789";
    char *p;
    char *q;
    p = ch1;
    q = ch2;
    int i = 10;
	while(*q != '\0')
    {
	ch1[i] = *q;
	p++;
	q++;
	i++;
    }
    printf("%s\n",ch1);
    return 0;
}
