#include <iostream>

using namespace std;

class A
{
    protected:
        int m_a;
    public:
        A()
        {   
            m_a = 999;
            cout<<"A的无参构造函数"<<endl;
        }
        A(int a)
        {
            m_a = 888;
            cout<<"A的有参构造函数"<<endl;
        }
};

class B:public A
{
    private:
        int b_a;
    public:
        B(int b):b_a(b)
        {}
        void show()
        {
            cout<<m_a<<b_a<<endl;
        }      
};

int main(int argc, char const *argv[])
{
    B b(10);
    b.show();
    return 0;
}
