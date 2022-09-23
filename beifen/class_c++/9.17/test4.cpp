#include <iostream>

using namespace std;

class Demo
{
    friend class A;
    private:
        int num;
    public:
        Demo()
        {
            num = 8;
        }
};

class A
{
    public:
        void print(Demo &d)
        {
            cout << d.num <<endl;
        }
};


int main(int argc, char const *argv[])
{
    //friend int print();
    Demo d1;
    A a1;
    a1.print(d1);
    return 0;
}
