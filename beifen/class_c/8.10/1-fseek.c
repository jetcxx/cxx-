#include <stdio.h>


char ch = 0;
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./1.txt","r+");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    //文件中的数据为helloworld


    //从文件的末尾向后偏移----空洞文件
    fseek(fp,2000,SEEK_END);
    fputc('a',fp);


    ch = fgetc(fp);
    printf("ch = %c\n",ch);
    fseek(fp,1,SEEK_CUR);   //从当前位置向后偏移一个字节
    ch = fgetc(fp);
    printf("ch = %c\n",ch);
    fseek(fp,-1,SEEK_END);
    ch = fgetc(fp);
    printf("ch = %c\n",ch);
    return 0;
}