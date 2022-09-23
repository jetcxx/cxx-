#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	char str[] = "helloworld";
	//使用%s输出一个字符串
	printf("str = %s\n",str);

	char str1[32] = "hello\0world";
	printf("str1 = %s\n",str1);
	//sizeof:计算数据类型所占内存的大小
	//strlen:计算的是字符串的长度（不带\0）
	printf("sizeof(str) =%ld\n",sizeof(str));
	printf("strlen(str) =%ld\n",strlen(str));
	return 0;
}
