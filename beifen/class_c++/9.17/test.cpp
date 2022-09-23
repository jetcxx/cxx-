#include <iostream>

using namespace std;

class Demo
{
    private:
        int num;
        char name[32];
    public:
        /*Demo()
        {
            cout<<"demo的无参构造函数"<<endl;
        }*/
        Demo(int x)
        {
            cout<<"demo的有一个参数的构造函数"<<endl;
        }
};

int main(int argc, char const *argv[])
{
    Demo d1(1);
    Demo d2 = d1;
    return 0;
}
