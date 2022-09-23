#include <iostream>

using namespace std;

void func(int x,int y,int z = 200)
{
    cout<< x + y <<endl;
}

int main(int argc, char const *argv[])
{
    int a = 100,b = 200;
    func(a,b);
    func(a,b,100);
    return 0;
}
