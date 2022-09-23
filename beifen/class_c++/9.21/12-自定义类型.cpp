#include <iostream>
using namespace std;
class Parent
{
private:
    int a;
public:
    enum{ID = 0};
    virtual int GetId()
    {
        return ID;
    }
};

class Child:public Parent
{
public:
    int array[102400];
public:
    enum{ID = 1};
    int GetId()
    {
        return ID;
    }
};

void func(Parent *p)
{
    if(p->GetId() == Child::ID)
    {
        Child *c = (Child *)p;
        c->array[102400 - 1] = 100;
    }
    else
    {
        cout<<"不能转换"<<endl;
    }
    
}

int main(int argc, char const *argv[])
{
    Parent *p = new Child;
    //Parent *p = new Parent;
    func(p);
    return 0;
}
