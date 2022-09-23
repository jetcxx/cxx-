#include <iostream>
using namespace std;

class A
{
public:
    A(int a):m_a(a)
    {

    }
public:
    virtual void print()
    {
        cout<<"AA"<<endl;
        cout<< "m_a = "<< m_a<<endl;
    }
public:   
    int m_a;
};

class B : public A
{
public:
    B(int a,int b):A(a),m_b(b)
    {

    }
public:
    void print()
    {
        cout<<"BB"<<endl;
        cout<<"m_a = "<<m_a<<"m_b = "<<m_b<<endl;
    }
public:
    int m_b;
};

int main(int argc, char const *argv[])
{
    //虚函数使用条件 ： 1.继承有函数遮蔽 2.基类指针指向派生类对象
    A *pa = new A(1);
    B *pb = new B(2,3);
    // A a(1);
    // B b(2,3);
    // a = b; //向上转型
    pa = pb;
    pa->print();
    pb->print();
    return 0;
}
