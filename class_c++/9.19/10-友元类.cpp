#include <iostream>
using namespace std;

class A
{
    friend class B;
    private:
        int m_a;
    public:
        A():m_a(10)
        {

        }
};
class B
{
    friend class A;
    private:
        int m_b;
    public:
        void print(A &a)
        {
            cout<<a.m_a<<endl;
        }
};

int main(int argc, char const *argv[])
{
    A a1;
    B b1;
    b1.print(a1);
    return 0;
}
