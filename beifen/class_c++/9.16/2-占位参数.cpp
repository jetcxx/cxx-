#include <iostream>
using namespace std;
struct A
{
    unsigned int a:10;
    unsigned int :20;
    unsigned char c:2;
};

void func(int a,int b,int = 0)
{
    cout<< a + b <<endl;
}

int main(int argc, char const *argv[])
{
    func(1,2,3);
    cout<< sizeof(A) <<endl;
    return 0;
}
