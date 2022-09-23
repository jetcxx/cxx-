#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Date
{
    private:
        int m_year;
        int m_month;
        int m_day;
    public:
        Date(int y,int m,int d)
        {
            cout<<"Date的有参构造函数"<<endl;
            m_year = y;
            m_month = m;
            m_day = d;
        }
        void show()
        {
            cout<<"year = "<<m_year<<" m_month = "<<m_month<<" m_day = "<<m_day<<endl;
        }
};
//形参的初始化列表:1.

class Student
{
    private:
        const int m_id;
        string m_name;
        Date m_birth;
    public:
        Student(int i,int y,int m,int d,string name):m_birth(y,m,d),m_id(i),m_name(name)
        {
            
        }
        void show()
        {
            cout<<"name = "<<m_name<<" id = "<<m_id<<endl;
            m_birth.show();
        }
};


int main(int argc, char const *argv[])
{
    Student s1(100,1997,12,4,"zhangsan");
    s1.show();
    return 0;
}
