#include <stdio.h>
#include <stdbool.h>
int main(int argc, const char *argv[])
{
	//定义一个bool类型变量并赋值为10
	//注意:c语言默认不支持bool类型需要添加stdbool.h头文件
	//bool类型只有两个0和1，非0即为真，
	//bool类型主要用于判断语句，判断条件是否成立
	bool b = 10;
	
	//%d：输出整型数据
	printf("b = %d\n",b);

	bool c = 0;

	printf("c = %d\n",c);
	bool d = 0.00000045;
	printf("d = %d\n",d);
	return 0;
}
