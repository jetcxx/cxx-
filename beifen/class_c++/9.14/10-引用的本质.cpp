#include <iostream>
using namespace std;

struct test
{
    int &a;
    int &b;
    char &c;
};

int main(int argc, char const *argv[])
{
    char ch = 'c';
    char &ch1 = ch;
    cout<<sizeof(ch1)<<endl;
    cout<<sizeof(test)<<endl;    
    return 0;
}
