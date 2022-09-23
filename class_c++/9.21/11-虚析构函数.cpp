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
    Parent()
    {
        cout<<"Parent的构造函数"<<endl;
    }
    virtual ~Parent()
    {
        cout<<"Parent的虚析构函数"<<endl;
    }
};

class Child:public Parent
{
public:
    virtual void show()
    {
        cout<<"this is child"<<endl;
    }
    Child()
    {
        cout<<"child的构造函数"<<endl;
    }
    ~Child()
    {
        cout<<"child的析构函数"<<endl;
    }
};


int main(int argc, char const *argv[])
{
    Parent *p1 = new Child;
    p1->show();
    delete p1;
    return 0;
}
