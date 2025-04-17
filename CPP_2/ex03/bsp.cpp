#include "Point.hpp"

static int checkPoint(const Point& a, const Point& b, const Point& toCheck)
{
	Fixed line = (a.getY() - b.getY()) * toCheck.getX() +
				(b.getX() - a.getX()) * toCheck.getY() +
				(a.getX() * b.getY()) - (b.getX() * a.getY());
	return (line.getRawBits());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int side1 = checkPoint(a ,b , point);
	int side2 = checkPoint(b ,c , point);
	int side3 = checkPoint(c ,a , point);

	if (side1 < 0 && side2 < 0 && side3 < 0)
		return (true);
	if (side1 > 0 && side2 > 0 && side3 > 0)
		return (true);
	return (false);	
}

