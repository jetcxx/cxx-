#include <iostream>

using namespace std;
class Complex
{
    friend ostream& operator<<(ostream &out,Complex &c);
private:
    int m_a;
    int m_b;
public:
    Complex(int a,int b)
    {
        m_a = a;
        m_b = b;
    }
    void print()
    {
        cout<<m_a<<" + "<<m_b<<"i"<<endl;
    }
    Complex operator+(Complex &c)
    {
        Complex t(0,0);
        t.m_a = c.m_a + this->m_a;
        t.m_b = c.m_b + this->m_b;
        return t;
    }
    
};

ostream& operator<<(ostream &out,Complex &c)
{
    out<<c.m_a<<" + "<<c.m_b<<"i";
    return out;
}

int main(int argc, char const *argv[])
{
    Complex c1(1,2);
    Complex c2(2,3);
    Complex c(0,0);
    c = c1 + c2;
    c.print();
    cout<<c<<endl;
    return 0;
}
