#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    //二维数组的动态创建
    int **a = new int *[5]; //先创建一个指针数组
    for(int i = 0;i < 5;i++)
    {
        a[i] = new int[6];//为指针数组中每一个成员开辟空间
    }
    //使用delete进行内存释放，只要顺序反过来就行
    for(int i = 0;i < 5;i++)
    {
        delete []a[i];
    }
    delete []a;
    return 0;
}
