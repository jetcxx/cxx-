#include <iostream>
using namespace std;
class TestA
{
private:
    int m_a;
public:
    void show()
    {
        cout<<"this is TestA"<<endl;
    }
};

class TestB : public TestA
{
private:
    int m_a;
public:
    void show()
    {
        cout<<"this is TestB"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    //TestA a;
    TestB b;
    cout<<sizeof(b)<<endl;
    //a.show();
    b.show();//默认调用派生类的同名函数
    b.TestA::show();
    return 0;
}
