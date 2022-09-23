#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include <iostream>
#include <math.h>
using namespace std;


class point
{
    private:
        double p_x;
        double p_y;
    public:
        void SetValue(double x,double y);
        double point_point(point &p);

};
class circle
{
    private:
        point center;
        double radius;
    public:
        void SetValue(double c_x,double c_y,double r);//设置圆心和半径
        bool point_circle(point &p);//计算点和圆的关系
    
};

#endif