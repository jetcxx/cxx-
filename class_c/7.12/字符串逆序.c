#include <stdio.h>
int main()
{
    char str[32] = {0};
    printf("输入一个字符串:\n");
    scanf("%s",str);
    int i = 0,length = 0;
    while(str[i] != '\0')
    {
	length++;
	i++;
    }
    int x = 0,y = length - 1;
    for(i = 0; i < length /2;i++)
    {
	char t =str[x];
	str[x] = str[y];
	str[y] = t;
	x++;
	y--;
    }
    printf("%s\n",str);
    return 0;
}
