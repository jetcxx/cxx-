#include <stdio.h>
int main(int argc, const char *argv[])
{
    char buf[123] = {0};
    fgets(buf,123,stdin);//从标准输入流中读取数据
    //printf("buf = %s\n",buf);
    //fprintf(stdout,"helloworld--%s",buf);
    fprintf(stderr,"helloworld--%s",buf);
    return 0;
}