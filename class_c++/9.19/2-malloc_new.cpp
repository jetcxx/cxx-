#include <iostream>

using namespace std;

class Test
{
    public:
        Test()
        {
            cout<<"Test的构造函数"<<endl;
        }
        Test(int a,int b)
        {
            cout<<"Test的有两个参数的构造函数"<<endl;
        }
        ~Test()
        {
            cout<<"Test的析构函数"<<endl;
        }
};


int main(int argc, char const *argv[])
{
    //Test t1; // 栈空间创建对象
    // Test *pt = (Test *)malloc(sizeof(Test));
    // if(nullptr == pt)  //c++中使用nullptr代替NULL
    // {
    //     cout<< "malloc failure" <<endl;
    // }
    // free(pt);


    // Test *pt2 = new Test;  //申请内存（堆）  自动调用构造函数
    // delete pt2;


    // int *p1 = new int; //给一个整型开辟空间  //自动置为0
    // cout<<*p1<<endl;
    // delete p1;

    // char *p2 = new char;
    // cout<<*p2<<endl;
    // delete p2;



    int *p3 = new int(10); //给一个整型开辟空间并初始化为10
    cout<<*p3<<endl;
    delete p3;


    Test *p4 = new Test(10,20);
    delete p4;


    char *p5 = new char[5]{'a','b','c','d','e'};
    for(int i = 0;i < 5;i++)
    {
        cout<<p5[i];
    }
    delete []p5;




    Test *p6 = new Test[10];
    delete []p6;
    return 0;
}
