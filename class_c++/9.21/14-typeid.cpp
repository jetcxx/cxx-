#include <iostream>
#include <typeinfo>
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
    if(typeid(*p) == typeid(Child))
    {
        cout<<"转换成功"<<endl;
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
    int a;
    char b;
    float c;
    double d;
    const type_info &pa = typeid(a);
    const type_info &pb = typeid(b);
    const type_info &pc = typeid(c);
    const type_info &pd = typeid(d);
    cout<<pa.name()<<endl;
    cout<<pb.name()<<endl;
    cout<<pc.name()<<endl;
    cout<<pd.name()<<endl;
    return 0;
}
