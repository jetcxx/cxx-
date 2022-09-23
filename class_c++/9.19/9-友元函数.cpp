#include <iostream>
using namespace std;
class Test
{
    friend void show(Test &t);
    private:
        int m_a;
        int m_b;
    public:
        Test()
        {
            m_a = 100;
            m_b = 200;
        }
};
void show(Test &t)
{
    cout<<t.m_a<<" "<<t.m_b<<endl;
}

int main(int argc, char const *argv[])
{
    Test t1;
    show(t1);
    return 0;
}
