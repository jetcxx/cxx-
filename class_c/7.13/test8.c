#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
//char s1[32] = "helloworld";
//char s2[32] = "abcdefg";
//strcat是将s2第一个\0之前的内容追加到s1\0开始的位置
//注意：strcat的第一个参数的空间必须保证足够大，否则会出现意想不到的情况
char s1[32] = "helloworld";
char s2[32] = "abcd\0efg";
strcat(s1,s2);
printf("s1 = %s\n",s1);
printf("s2 = %s\n",s2);
return 0;
}
