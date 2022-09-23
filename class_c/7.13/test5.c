#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
char s1[] = "helloworld";
printf("strlen(s1) = %ld\n",strlen(s1));
printf("sizeof(s1) = %ld\n",sizeof(s1));
char s2[] = "hellowor\0ld";
printf("strlen(s2) = %ld\n",strlen(s2));
printf("sizeof(s2) = %ld\n",sizeof(s2));
//char s1[] = "hello";
char s3[] = {'h','e','l','l','o'};
printf("strlen(s3) = %ld\n",strlen(s3));
printf("sizeof(s3) = %ld\n",sizeof(s3));
return 0;
}
