#include <iostream>

using namespace std;
int g_num = 200;

int &f1()
{
    int num = 100;
    return g_num;
}

int main(int argc, char const *argv[])
{
    int a = f1();
    a = 999;
    cout<<"g_num = "<<g_num<<endl;
    
    int &b = f1();
    b = 888;

    cout<<"g_num = "<<g_num<<endl;
    f1();
    f1() = 1000;
    cout<<"g_num = "<<g_num<<endl;
    return 0;
}
