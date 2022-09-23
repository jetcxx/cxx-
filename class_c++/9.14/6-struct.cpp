#include <iostream>
#include <cstring>

using namespace std;

struct student
{
    char name[32];
    void func()
    {
        cout<<"this is:"<<name<<endl;
    }
};

int main(int argc, char const *argv[])
{
    student s1;
    strcpy(s1.name,"zhangsan");
    s1.func();
    return 0;
}
