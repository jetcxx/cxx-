#include <iostream>
using namespace std;

class Date
{
    private:
        int m_year;
        int m_month;
        int m_day;
    public:
        /*Date()
        {
            cout<<"data的构造函数"<<endl;
            m_year = 1937;
            m_month = 7;
            m_day = 7;
        }*/
        Date(int y,int m,int d)
        {
            cout<<"Date有参构造函数"<<endl;
            m_year = y;
            m_month = m;
            m_day = d;
        }
};
//对象的初始化列表：1.类对象作为成员变量并且该类没有提供无参构造函数，2.成员变量用const修饰
class Student
{
    private:
        const int id;
        Date birth;
    public:
        Student(int i,int y,int m,int d):birth(y,m,d),id(i)
        {
            cout<<"student的有参构造函数"<<endl;
            //id = i;
        }
};
int main(int argc, char const *argv[])
{
    Student s1(1000,1999,1,1);
    return 0;
}

