#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./1.txt","r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    while (1)
    {
        int ret = fgetc(fp);
        if(EOF == ret)
        {
            if(feof(fp))
            {
                printf("到达文件末尾\n");
                break;
            }
            else
            {
                printf("获取失败\n");
                return -1;   
            }
        }
        printf("获取到的数据为:%d----所对应的字符为:%c\n",ret,ret);
    }
    if(fclose(fp) == EOF)
    {
        printf("关闭失败\n");
        return -1;
    }
    
    return 0;
}
