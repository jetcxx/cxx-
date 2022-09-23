#include "cube.h"

void cube::setValue(double a,double b,double c)
{
    m_a = a;
    m_b = b;
    m_c = c;

}

double cube::GetArea()
{
    double MyArea;
    MyArea = 2*m_a*m_b + 2*m_b*m_c + 2*m_a*m_c;
    return MyArea;
}

double cube::GetVolume()
{
    return m_a*m_b*m_c;
}

bool cube::CubeIsEqual(cube &c)
{
    if(m_a == c.m_a && m_b == c.m_b && m_c == c.m_c)
    {      
        return true;
    }
    else
    {
        return false;
    }
}