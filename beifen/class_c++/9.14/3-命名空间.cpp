#include <iostream>

using namespace std;

namespace zhangsan
{
    int num = 100;
    void func()
    {
        cout<<"this is zhangsan"<<endl;
    }
}

namespace lisi
{
    int num = 200;
    void func()
    {
        cout<<"this is lisi"<<endl;
    }
}

void test1()
{
    cout<<"zhangsan:num"<<zhangsan::num<<endl;
    cout<<"lisi:num"<<lisi::num<<endl;
}

void test2()
{
    using zhangsan::num;
    cout<<"zhangsan num:"<<num<<endl;
    num = 999;
    cout<<"zhangsan num:"<<num<<endl;
    //func();
    using lisi::func;
    func();
}

int main(int argc, char const *argv[])
{
    test2();
    return 0;
}
