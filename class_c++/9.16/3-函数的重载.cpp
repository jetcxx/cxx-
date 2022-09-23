#include <iostream>
using namespace std;

void func(int a,float b)
{
    cout<<"int a,float b "<<endl;
    cout<< a + b <<endl;
}
void func(float a,float b)
{
    cout<< a + b <<endl;
}
void func(int a,int b, int c)
{
    cout<< a + b + c <<endl;
}
int func(float a,int b)
{
    cout<<"float a, int b"<<endl;
    cout<< a + b <<endl;
}

int main(int argc, char const *argv[])
{
    int a = 100,b = 200;
    float f1 = 3.14,f2 = 6.78;
    func(f1,f2);
    func(a,b,200);
    func(a,f1);
    func(f2,b);
    return 0;
}
