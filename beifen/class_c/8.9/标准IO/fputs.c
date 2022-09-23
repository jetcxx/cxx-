#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./1.txt","w");
    if(fp == NULL)
    {
        perror("fopen");
        return -1;
    }
    char buf[123] = "123456789";
    if(EOF == fputs(buf,fp))
    {
        perror("fputs");
        return -1;
    }
    fclose(fp);
    return 0;
}
