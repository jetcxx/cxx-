#ifndef _CUBE_H_
#define _CUBE_H_
#include <iostream>

using namespace std;

class cube
{
    private:
        double m_a;//长
        double m_b;//宽
        double m_c;//高
    public:
        //设置属性
        void setValue(double a,double b,double c);
        //求面积
        double GetArea();
        //求体积
        double GetVolume();
        //判断两个立方体是否相等
        bool CubeIsEqual(cube &c);
};

#endif