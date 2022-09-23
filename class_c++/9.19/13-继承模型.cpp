#include <iostream>
using namespace std;
class Person
{
    public:
        int m_age;
};
class Student:public Person
{
    public:
        char m_ch[23];
};

int main(int argc, const char *argv[])
{
    Student s1;
    cout<<sizeof(s1)<<endl;
    cout<<&s1<<endl;
    cout<<&s1.m_age<<endl;
    cout<<&s1.m_ch<<endl;
    return 0;
}