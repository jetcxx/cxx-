#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 10;
    static int count = num; //在c++中，在编译阶段开辟空间，在运行阶段赋值
    return 0;
}
