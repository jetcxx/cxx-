#include <stdio.h>

void ptr()
{
    char ptr[100] = "hello";
    //ptr  *ptr   &ptr  *(&ptr)  
    printf("%s\n",ptr);//一维数组首元素地址  +1为首地址加一
    printf("%c\n",*ptr); // 一维数组首元素
    printf("%s\n",&ptr);//一维数组地址  +1为100字节
    printf("%s\n",*(&ptr)); // = ptr  一维数组的地址取值 为 一维数组首元素的地址
}

void ktr()
{
    char ktr[2][100] = {"hello1","hello2"};
    //str  *str  &str  *(&str)  **str
    printf("%s\n",ktr);//二维数组的首个一维数组的地址
    printf("%s\n",*ktr);//二维数组的首个一维数组的首元素的地址
    printf("%s\n",&ktr);//二维数组的地址
    printf("%c\n",**ktr);//二维数组的首个一维数组的首元素的值
    printf("%s\n",*(&ktr));// = str  二维数组的首个一维数组的地址
}

void str()
{
    char str[2][2][100] = {{"hello3","hello4"},{"hello5","hello6"}};
    printf("%s\n",str);//三维数组中首个二维数组的地址
    printf("%s\n",&str);//三维数组的地址
    printf("%s\n",*str);//三维数组中首个二维数组的首个一维数组的地址
    printf("%s\n",**str);//三维数组中首个二维数组的首个一维数组的首元素的地址
    printf("%c\n",***str);//三维数组中首个二维数组的首个一维数组的首元素的值

}

void wtr()
{
    char *wtr[3] = {"hello7","hello8","hello9"};
    //指针数组实际上还是一维数组，只不过保存的是指针
    printf("%s\n",wtr);
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
