#include <stdio.h>
int main()
{
    char str[32] = "helloworld";
    char j;
    printf("输入在第几个字符后插入一个字符:");
    scanf("%d %c\n",str);
    int i = 0,length = 0;
    while(str[i] != '\0')
    {
	length++;
	i++;

    
