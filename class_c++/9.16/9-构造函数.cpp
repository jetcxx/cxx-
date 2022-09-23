#include <iostream>

using namespace std;
class Array
{
    private:
        int *m_data;//保存数组首元素的地址
        int m_size;//数组的大小
    public:
        Array(); //无参构造函数
        Array(int size);//有参构造函数
        Array(int size,int s);//有两个参数的构造函数
        Array(const Array &a);
        void SetVal(int Index,int value);
        int GetValue(int Index);
        void GetSize();
};

Array::Array(const Array &a)
{
    cout<<"Array的拷贝构造函数"<<endl;
}
void Array::GetSize()
{
    cout<<"m_size = "<<m_size<<endl;
}
Array::Array()
{
    cout<<"Array的无参构造函数"<<endl;
    m_size = 5;
    m_data = (int *)malloc(sizeof(int) * m_size);
}
Array::Array(int size)
{
    cout<<"有一个参数的构造函数"<<endl;
    m_size = size;
    m_data = (int *)malloc(sizeof(int)* m_size);
}
Array::Array(int size,int s)
{
    cout<<"有两个参数的构造函数"<<endl;
    m_size = size;
    m_data = (int *)malloc(sizeof(int) * m_size);
}

void Array::SetVal(int Index,int value)
{
    m_data[Index] = value;
}

int Array::GetValue(int Index)
{
    return m_data[Index];
}

int main(int argc, char const *argv[])
{
    Array a1(10);
    for(int i = 0; i < 10;i++)
    {
        a1.SetVal(i,i+1);
    }
    for(int i = 0;i < 10;i++)
    {
        cout<<a1.GetValue(i)<<" ";
    }
    cout<<endl;
    Array a4 = (10,20);
    a4.GetSize();
    Array a5 = (a1);
    for(int i = 0;i < 10;i++)
    {
        cout<<a5.GetValue(i)<<" ";
    }
    return 0;
}
