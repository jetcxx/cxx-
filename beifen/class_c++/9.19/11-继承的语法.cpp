#include <iostream>

using namespace std;
class Person
{
    protected:
        double m_high;
        double m_weight;
    public:
        Person()
        {
            m_high = 1.98;
            m_weight = 80;
        }
};
class Student:public Person
{
    private:
        int m_id;
    public:
        Student(int id):m_id(id)
        {

        }
        void show()
        {
            cout<<"m_high = "<<m_weight<<"m_weight = "<<m_weight<<"m_id = " <<m_id<<endl;
        }
};
int main(int argc, char const *argv[])
{
    Student s1(10);
    s1.show();
    return 0;
}
