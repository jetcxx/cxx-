#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1],"r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    int count = 0;
    //开始计算
    while(1)
    {
        char buf[123] = {0};
        if(NULL == fgets(buf,sizeof(buf),fp))
        {
            //出错或者到了文件末尾
            if(feof(fp))
            {
                printf("到达了文件的末尾\n");
                break;
            }
            else
            {
                perror("fgets");
                return -1;
            }
        }
        if(buf[strlen(buf) - 1] == '\n')
        {
            printf("buf = %s\n",buf);
            count++;
        }
        
    }
    count++;
    printf("该文件的行数为:%d\n",count);
    fclose(fp);
    return 0;
}