#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a = 100;
    int &pa = a;
    const int &pb = a;
    a++;
    cout<<"a = "<<a<<endl;
    const int &pc = 100;
    int *p = (int *)&pc;
    (*p)++;
    cout<<"pc = "<<pc<<endl;
    return 0;
}
