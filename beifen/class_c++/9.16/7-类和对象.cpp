#include <iostream>
#include <cstring>
using namespace std;

struct student
{
    int age;
    char name[32];
};

class student1
{
    public:
    int age;char name[32];
    void func()
    {
        cout<<"hello world"<<endl;
        cout<<name<<"的年龄是:"<<age<<endl;
    }
};

int main(int argc, char const *argv[])
{
    student s1;
    s1.age = 18;
    student1 s2,s3;
    s2.age = 19;
    strcpy(s2.name,"zhangsan");
    s2.func();
    s3.age = 29;
    strcpy(s3.name,"lisi");
    s3.func();
    cout<<sizeof(s2)<<endl;
    return 0;
}
