#include <stdio.h>
#include <string.h>
int main()
{
    char s1[] = "helloworld";
    printf("strlen(s1) = %ld\n",strlen(s1));
    printf("sizeof(s1) = %ld\n",sizeof(s1));

    char s2[] = "hellowor\0ld";
    printf("strlen(s2) = %ld\n",strlen(s2));
    printf("sizeof(s2) = %ld\n",sizeof(s2));
    
    return 0;
}
