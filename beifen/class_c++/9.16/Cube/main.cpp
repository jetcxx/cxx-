#include "cube.h"

int main(int argc, char const *argv[])
{
    cube c1,c2;
    c1.setValue(1,2,3);
    c2.setValue(2,3,4);
    cout<<"c1的面积是："<<c1.GetArea()<<endl;
    cout<<"c1的体积是："<<c1.GetVolume()<<endl;
    cout<<"c2的面积是："<<c2.GetArea()<<endl;
    cout<<"c2的体积是："<<c2.GetVolume()<<endl;
    if(c1.CubeIsEqual(c2))
    {
        cout<<"两个立方体相等"<<endl;
    }
    else
    {
        cout<<"两个立方体不相等"<<endl;
    }
    return 0;
}
