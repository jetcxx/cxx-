#include <iostream>
using namespace std;

class Complex
{
private:
    int m_a;
    int m_b;
public:
    Complex(int a,int b)
    {
        m_a = a;
        m_b= b;
    }
    void print()
    {
        cout<<m_a<<" + "<<m_b<<"i"<<endl;
    }
    Complex operator-(Complex &c)
    {
        Complex t(0,0);
        t.m_a = this->m_a - c.m_a;
        t.m_b = this->m_b - c.m_b;
        return t;
    }
};


int main(int argc, char const *argv[])
{
    Complex c1(4,3);
    Complex c2(1,2);
    Complex c(0,0);
    c = c1 - c2;
    c.print();
    return 0;
}
