#include <iostream>
using namespace std;

#define MAX(a,b) (a) > (b) ? a : b

inline int MyMax(int a,int b)  //只需要在函数定义前加上inline关键词即可
{
    return (a > b) ? a : b;
}
int main(int argc, const char *argv[])
{
    int a = 100,b = 200;
    int res = MyMax(a,b);
    cout<<res<<endl;
    return 0;
}