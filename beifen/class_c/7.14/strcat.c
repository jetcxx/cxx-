#include <stdio.h>
int main()
{
    char s1[32] = "helloworld";
    char s2[32] = "123456789";
    int i = 0,j = 0;
    while(s1[i] != '\0')
    {
	i++;
    }
    while(s2[j] != '\0')
    {
	s1[i] = s2[j];
	i++;
	j++;
    }
    s1[i] = s2[j];
    printf("s1 = %s\n",s1);
    return 0;
}
