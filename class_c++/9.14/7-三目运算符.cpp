#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 1,b = 0;
    int num =  a > b ? a : b;
    (a < b) ? a : b = 100;
    cout<<"b = "<<b<<endl;
    return 0;
}
