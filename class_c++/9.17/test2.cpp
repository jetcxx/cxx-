#include <iostream>
using namespace std;

class Demo
{
    public:
        Demo()
        {
            cout<<"Demo的构造函数"<<endl;
        }
        ~Demo()
        {
            cout<<"Demo的析构函数"<<endl;
        }
};


int main(int argc, char const *argv[])
{
    Demo *str = new Demo;
    delete str;
    return 0;
}
