#include <iostream>
#include <cstring>
using namespace std;
class Person
{
    protected:
        char name[32];
        int age;
    public:
        Person(const char *n,int a)
        {
            cout<<"Person的有参构造函数"<<endl;
            strcpy(name,n);
            age = a;
        }
        ~Person()
        {
            cout<<"Person的析构函数"<<endl;
        }
};
class Date
{
    private:
        int m_year;
        int m_month;
        int m_day;
    public:
        Date(int y,int m,int d)
        {
            cout<<"Date有参构造函数"<<endl;
            m_year = y;
            m_month = m;
            m_day = d;
        }
        ~Date()
        {
            cout<<"Date的析构函数"<<endl;
        }
};
class Student:public Person
{
    private:
        Date birth;
        int id;
    public:
    //当基类没有提供无参构造函数的时候，派生类需要通过对象初始化列表来传参
        Student(int i):Person("aaa",23),birth(1997,1,1)
        {
            cout<<"Student的构造函数"<<endl;
            id = i;
        }
        void show()
        {
            cout<<name<<" "<<age<<" "<<id<<endl;
        }
        ~Student()
        {
            cout<<"Student的析构函数"<<endl;
        }
};
int main(int argc, char const *argv[])
{
    Student s1(1000);
    s1.show();
    return 0;
}
