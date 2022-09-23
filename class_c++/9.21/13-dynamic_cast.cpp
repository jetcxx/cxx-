#include <iostream>
using namespace std;
class Parent
{
private:
    int a;
public:
    virtual void func(){}
};

class Child:public Parent
{
public:
    int array[102400];
public:
    virtual void func(){}
};

void func(Parent *p)
{
    Child *c = dynamic_cast<Child *>(p);
    if(NULL == c)
    {
        cout<<"不能转换"<<endl;
    }
    else
    {
        cout<<"转换成功"<<endl;
        Child *c = (Child *)p;
        c->array[102400 - 1] = 100;
    }    
}

int main(int argc, char const *argv[])
{
    Parent *p = new Child;
    //Parent *p = new Parent;
    func(p);
    return 0;
}
