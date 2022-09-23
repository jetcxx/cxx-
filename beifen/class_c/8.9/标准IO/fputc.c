#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./1.txt","w");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    char buf[123] = "hello world";
    int i = 0;
    while (1)
    {
        fputc(buf[i],fp);
        if(strlen(buf)-1 == i)
        {
            break;
        }
        i++;
    }
    fclose(fp);
    return 0;
}
