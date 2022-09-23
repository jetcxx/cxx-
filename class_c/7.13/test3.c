#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
//char ch2[] = "helloworld";
char ch1[] ={'h','e','l','l','o'};
//printf("sizeof(ch1) = %ld\n",sizeof(ch1));
//printf("sizeof(ch2) = %ld\n",sizeof(ch2));
/*int i;
for(i = 0; i < sizeof(ch1)/sizeof(ch1[0]);i++)
{
printf("%c",ch1[i]);
}
*/
printf("ch1 = %s\n",ch1);
return 0;
}
