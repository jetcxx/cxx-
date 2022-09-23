#include <iostream>
using namespace std;
void func(int x,int y)
{
    cout<<x + y<<endl;
}
void func(int &x,int &y)
{
    cout<<x + y<<endl;
}

int main(int argc, char const *argv[])
{
    int a = 100,b = 200;
    func(a,b);
    return 0;
}
