#include <stdio.h>
int main()
{
    char buf[32] = {0};
    printf("输入一个字符:\n");
    gets(buf);

    long i = 0;
    while(buf[i] != 0)
    {
	i++;
    }
    printf("strlen(buf) = %ld\n",i);
    return 0;
}
