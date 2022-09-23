#include <iostream>

using namespace std;
int g_count;
class Student
{
    private:
        int id;
    public:
        static int m_count;
        int high;
        Student()
        {
            high = 10;
            m_count++;
            id = m_count;
        }
        static int GetCount()
        {
            g_count++;
            return m_count;
        }
        int GetCount1()
        {
            return m_count;
        }
};
int Student::m_count = 0; //静态成员变量必须在类外部进行初始化，不初始化，系统不会为其开辟内存空间
int main(int argc, char const *argv[])
{
    Student s1;
    Student s2;
    cout<<s1.GetCount()<<endl;
    cout<<s2.GetCount()<<endl;
    cout<<Student::GetCount()<<endl;
    cout<<Student::m_count<<endl;
    cout<<s1.GetCount1()<<endl;
    return 0;
}
