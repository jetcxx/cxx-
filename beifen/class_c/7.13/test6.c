#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
//char s1[] = "hello world";
//char s2[] = "hello world";
//char s1[32] = "hello w\0orld";
//char s2[] = "hello w\0orld";
//char s1[32] = "hello w\0orlda";//strcmp比较的是两个字符串第一个\0之前的内容
//char s2[] = "hello w ";
char s1[32] = "hello ";//strcmp比较的是两个字符串第一个\0之前的内容
char s2[] = "hello ";
int ret = strcmp(s1,s2);
if(ret == 0)
{
printf("s1 = s2\n");
}
else if(ret > 0)
{
printf("s1 > s2\n");
}
else
{
printf("s1 < s2\n");
}


char s3[32] = "hello worlda";
char s4[] = "hello w ";
int k = strncmp(s3,s4,5);
if(k == 0)
{
printf("s3 = s4\n");
}
return 0;
}
