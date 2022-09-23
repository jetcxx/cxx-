#include <iostream>
#include <cstring>
using namespace std;

struct student
{
    char name[32];
    int id;
};

void GetMemory(student *&s)
{
    s = (student *)malloc(sizeof(student));
}

int main(int argc, char const *argv[])
{
    student * s1 = NULL;
    GetMemory(s1);
    strcpy(s1->name,"zhangsan");
    s1->id = 1000;
    cout<<"name = "<<s1->name<<endl<<"id = "<<s1->id<<endl;
    return 0;
}
