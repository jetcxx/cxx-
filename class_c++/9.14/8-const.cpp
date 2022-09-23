#include <iostream>

using namespace std;
const int a = 100;
int main(int argc, char const *argv[])
{
    // int *p = (int *)&a;
    // *p = 1;
    // cout<<a<<endl;


    const int b = 200;
    int *p2 = (int *)&b;
    //*p2 = 300;
    cout<<"b = "<<b<<endl;
    cout<<"*p2 = "<<*p2<<endl;
    return 0;
}
