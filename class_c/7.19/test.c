
#include <stdio.h>
 
int main(int argc, const char *argv[])
{
	char *p = NULL;
	char *tmp = "12345678";
	p = (tmp + 4);
	//p[-1] = ? p[-5] = ?
	printf("p[-1] = %c,p[-5] = %c\n",p[-1],p[-5]);
	return 0;
}
