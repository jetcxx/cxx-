#include <iostream>

using namespace std;

void Swap(int &x,int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main(int argc, char const *argv[])
{
    int a = 100,b = 200;
    cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
    Swap(a,b);
    cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
    return 0;
}
