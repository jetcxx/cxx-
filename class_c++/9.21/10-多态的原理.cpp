#include <iostream>
using namespace std;

class Parent
{
public:
    int m_a;
    virtual void show()
    {
        cout<<"this is parent"<<endl;
    }
};

class Child:public Parent
{
public:
    virtual void show()
    {
        cout<<"this is child"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Child c;
    Parent p;
    cout<<sizeof(c)<<endl;
    cout<<sizeof(p)<<endl;
    cout<<"&p = "<<&p<<endl;
    cout<<"&p.m_a = "<<&p.m_a<<endl;
    return 0;
}
