#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main (void)
{
    Point const a(2.0f, 2.0f);
	Point const b(7.0f, 7.0f);
	Point const c(12.0f , 2.0f);
	Point const point(2.0f , 2.0f);

	if (bsp(a,b,c,point))
		std::cout << "-- the point is inside -- " << std::endl;
	else
		std::cout << "-- the point is outside -- " << std::endl;
    return (0);
}