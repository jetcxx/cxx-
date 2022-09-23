#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
char s1[32];
//s1 = "helloworld"; //错误，除了初始化以外，不能通过数组名整体赋值
strcpy(s1,"helloworld");
printf("s1 = %s\n",s1);


char s2[32] = "helloworld";
char s3[32] = "abcdfeg";
strcpy(s2,s3);//strcpy函数将s3的第一个\0包括\0复制给s2
printf("s2 = %s\n",s2);
printf("s3 = %s\n",s3);

int i;
for (i = 0;i < 12;i++)
{
    printf("[%c]:%d\n",s2[i],s2[i]);
}

return 0;
}
