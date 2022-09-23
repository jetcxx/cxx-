#include <iostream>
using namespace std;

class Test
{
    public:
        Test(int a)
        {
            cout<<"Test的构造函数"<<endl;
        }
        ~Test()
        {
            cout<<"Test的析构函数"<<endl;
        }
};


int main(int argc, char const *argv[])
{
    Test t1 = Test(10);
    cout<<"+++++++++++++++"<<endl;
    return 0;
}
