#include "Point.hpp"

Point::Point(void){}

Point::Point(const float x, const float y):_x(x) , _y(y){}

Point::Point(const Point& rsc):_x(rsc.getX()),_y(rsc.getY()){}

Point::~Point(void){};

Point& Point::operator=(const Point& rsc)
{
	std::cerr << "Can not use = operator in const attributes" << std::endl;
	(void)rsc;
	return (*this);
}

const Fixed& Point::getX(void)const
{
return (this->_x);
}

const Fixed& Point::getY(void)const
{
return (this->_y);
}
