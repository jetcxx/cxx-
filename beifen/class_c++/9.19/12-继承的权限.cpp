#include <iostream>
using namespace std;
class TestA
{
    private:
        int m_a;
    protected:
        int m_b;
    public:
        int m_c;
};

class TestB:private TestA
{
    public:
        void test()
        {
            //m_a++;
            m_b++;
            m_c++;
        }
};

class TestC:protected TestA
{
    public:
    void test()
    {
        //m_a+++;
        m_b++;
        m_c++;
    }
};

class TestD:public TestA
{
    public:
        void test()
        {
            //m_a++;
            m_b++;
            m_c++;
        }
};

int main(int argc, char const *argv[])
{
    TestD d1;
    d1.test();
    d1.m_c;
    return 0;
}
