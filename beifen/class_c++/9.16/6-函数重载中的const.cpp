#include <iostream>
using namespace std;
void func(const int *x,const int *y)
{
    cout<<"const..."<<endl;
    cout<< *x + *y <<endl;
}

void func(int *x,int *y)
{
    cout<<"普通指针 "<<endl;
    cout<< *x + *y <<endl;
}

int main(int argc, char const *argv[])
{
    const int a = 100,b = 200;
    func(&a,&b);
    return 0;
}
