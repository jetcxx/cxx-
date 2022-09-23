#include <iostream>
using namespace std;

class Test
{
    public:
        Test(int a)
        {
            cout<<"Test的有参构造函数"<<endl;
        }
        Test(const Test &t)
        {
            cout<<"Test的拷贝构造函数"<<endl;
        }
};


int main(int argc, char const *argv[])
{
    Test t1(1);
    Test t2(t1);
    return 0;
}
