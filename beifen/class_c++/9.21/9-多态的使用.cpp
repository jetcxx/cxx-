#include <iostream>
using namespace std;

class Parent
{
public:
    virtual void show()
    {
        cout<<"this is parent"<<endl;
    }
};

class Child:public Parent
{
public:
    void show()
    {
        cout<<"this is child"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Child c;
    Parent p;
    p = c;
    p.show();
    Parent *p2 = new Parent;
    p2->show();
    return 0;
}
