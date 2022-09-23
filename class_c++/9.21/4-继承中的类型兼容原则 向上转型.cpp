#include <iostream>
using namespace std;
class Person
{
private:
    int m_a;
    int m_b;
public:
    Person()
    {
        cout<<"Person的无参构造函数"<<endl;
    }
};
class Student:public Person
{
private:
    int m_c;
    int m_d;
};

int main(int argc, char const *argv[])
{
    Student s;
    Person p;
    Person &p1 = s;
    return 0;
}
