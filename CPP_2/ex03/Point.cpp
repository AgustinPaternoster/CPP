#include "Point.hpp"

Point::Point(void){}

Point::Point(const float x, const float y):_x(x) , _y(y){}


Point::~Point(void)
{
    std::cout << "destructor called" << std::endl;
}

Point& Point::operator=(const Point& rsc)
{
     // vericar - no se puede modificar un valor constante
}

float Point::getXvalue(void)
{
    return (_y.toFloat());
}
