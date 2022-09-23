#include <iostream>

using namespace std;
class Horse
{
private:
    int m_a;
public:
    Horse(int a)
    {
        m_a = 50;
        cout<<"horse的有参构造函数"<<endl;
    }
    ~Horse()
    {
        cout<<"horse的无参构造函数"<<endl;
    }
    void show()
    {
        cout<<"m_a"<<m_a<<endl;
    }
};
class Bull
{
private:
    int m_b;
public:
    Bull(int b)
    {
        m_b = 100;
        cout<<"Bull的有参构造函数"<<endl;
    }
    ~Bull()
    {
        cout<<"Bull的析构函数"<<endl;
    }
    void show()
    {
        cout<<"m_b = "<<m_b<<endl;
    }
};
class Cat
{
private:
    int m_c;
public:
    Cat(int c)
    {
        m_c = c;
        cout<<"Cat的有参构造函数"<<endl;
    }
    ~Cat()
    {
        cout<<"Cat的析构函数"<<endl;
    }
};

class Dog:public Horse,public Bull
{
private:
    Cat c1;
public:
    Dog():Bull(10),Horse(50),c1(1000)
    {
        cout<<"dog的构造函数"<<endl;
    }
    ~Dog()
    {
        cout<<"dog的析构函数"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Dog d1;
    cout<<sizeof(d1)<<endl;
    d1.Bull::show();
    return 0;
}
