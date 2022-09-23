#include <iostream>
using namespace std;

class Test
{
private:
    int a;
    void func()
    {
        cout<<"hello world"<<endl;
    }
public:
    int b;
    void func2()
    {
        cout<<"nihao nanjing"<<endl;
    }
public:
    int c;
protected:
    int d;
};

int main(int argc, char const *argv[])
{
    Test t1;
    t1.b;
    t1.c;
    t1.d;
    return 0;
}
