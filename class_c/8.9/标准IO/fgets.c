#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./1.txt","r");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    while (1)
    {
        char buf[123] = {0};
        if(fgets(buf,12,fp) == NULL)
        {
            if(feof(fp))
            {
                printf("读到文件的末尾\n");
                break;
            }
            else
            {
                perror("fgets");
                return -1;
            }
            
        }
        printf("buf = %s\n",buf);
    }
    fclose(fp);
    return 0;
}
