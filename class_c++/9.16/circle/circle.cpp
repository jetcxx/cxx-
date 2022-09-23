#include "circle.h"


void circle::SetValue(double c_x,double c_y,double r)
{
    center.SetValue(c_x,c_y);
    radius = r;
}

bool circle::point_circle(point &p)
{
    if(p.point_point(center) < radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void point::SetValue(double x,double y)
{
    p_x = x;
    p_y = y;
}

double point::point_point(point &p)
{
    double distance;
    distance = sqrt((p_x - p.p_x)*(p_x - p.p_x) + (p_y - p.p_y)*(p_y - p.p_y));
    return distance;
}