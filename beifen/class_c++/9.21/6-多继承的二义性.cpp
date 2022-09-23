#include <iostream>
using namespace std;
class A
{
public:
    int m_a;
};
class B:virtual public A//虚继承
{
public:
    int m_b;
};
class C:virtual public A//虚继承
{
public:
    int m_c;
};

class D:public B,public C
{
public:
    int m_d;
};

int main(int argc, char const *argv[])
{
    D d1;
    cout<<sizeof(d1)<<endl;
    d1.m_a;
    return 0;
}
