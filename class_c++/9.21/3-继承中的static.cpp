#include <iostream>
using namespace std;
class Person
{
public:
    static int count;
public:
    Person()
    {
        count++;
    }
};

class Student : public Person
{

};
int Person::count = 0;
int main(int argc, char const *argv[])
{
    Person p1;
    Person p2;
    Person p3;
    Student s1;
    Student s2;
    Student s3;
    Student s4;
    cout<<Person::count<<endl;
    cout<<Student::count<<endl;
    return 0;
}
