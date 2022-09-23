#include <iostream>
#include <cstring>

using namespace std;
int g_num = 100;
class Student
{
private:
    char m_name[32];
    int m_age;
    int m_score;
public:
    static int count;
    Student(char *name,int age,int score);
    void show();
    ~Student();
    char *GetName() const;
    int GetAge() const;
    int Getscore() const;
};
int Student::count = 0;
int Student::GetAge() const
{
    return m_age;
}
int Student::Getscore() const
{
    return m_score;
}
Student::Student(char *name,int age,int score)
{
    cout<<"Student的构造函数"<<endl;
    strcpy(m_name,name);
    m_age = age;
    m_score = score;
}
void Student::show()
{
    cout<<"name = "<<m_name<<" age = "<<m_age<<" score = "<<m_score<<endl;
}
Student::~Student()
{
    cout<<"Student的析构函数"<<endl;
}
char *Student::GetName() const
{
    return (char *)m_name;
    count++;
    g_num++;
}

int main(int argc, char const *argv[])
{
    Student *s1 = new Student("zhangsan",19,98);
    s1->show();
    cout<<s1->GetName()<<endl;
    cout<<s1->GetAge()<<endl;
    cout<<s1->Getscore()<<endl;
    delete s1;
    return 0;
}
