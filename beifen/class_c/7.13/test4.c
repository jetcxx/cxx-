#include <stdio.h>
#include <string.h>
int main()
{
    char str[4][32] = {"hello world","nihao nanjing","hello kitty","nihaosuqian"};
    int x,y;
for(x = 0; x < 4;x++)
{
for(y = 0; y < 32;y++)
{
printf("%c",str[x][y]);
}
putchar(10);
}
     return 0;
}
