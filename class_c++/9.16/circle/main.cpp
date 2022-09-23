#include "circle.h"


int main(int argc, char const *argv[])
{
    point p1;
    p1.SetValue(3,4);
    circle c1;
    c1.SetValue(4,5,10);
    //cout<<"点与圆心距离为:"<<p1.point_point(c1)<<endl;
    if(c1.point_circle(p1))
    {
        cout<<"点在圆内"<<endl;
    }
    else
    {
        cout<<"点在圆外"<<endl;
    }
    return 0;
}
