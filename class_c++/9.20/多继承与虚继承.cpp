#include <iostream>

using namespace std;

class A
{
public:
    A(int a):m_a(a)
    {
        cout<< "AAA" <<endl;
    }
    int m_a;
};

class B : virtual public A
{
public:
    B(int b):m_b(b),A(2)
    {
        cout << "BBB" <<endl;
    }
    int m_b;
};

class C : virtual public A
{
public:
    C(int c):m_c(c),A(3)
    {
        cout << "CCC" << endl;
    }
    int m_c;
};

class D : public B, public C
{
public:
    D(int d):m_d(d),B(4),C(5),A(9)
    {
        cout << "DDD" << endl;
    }
    int m_d;
};


int main(int argc, char const *argv[])
{
    D d(8);
    cout << d.m_a <<endl; // 打印a时产生二义性问题，用虚继承解决，此时相当于D多了一个派生类A，此时A为虚基类；
    return 0;
}
