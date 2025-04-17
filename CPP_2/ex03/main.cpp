#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

// bool checkPoint(const Point a, const Point b, const Point toCheck);

static int checkPoint(const Point& a, const Point& b, const Point& toCheck)
{
	Fixed line = (a.getY() - b.getY()) * toCheck.getX() +
				(b.getX() - a.getX()) * toCheck.getY() +
				(a.getX() * b.getY()) - (b.getX() * a.getY());
	return (line.getRawBits());
}

int main (void)
{
    Point a(1.0f, 1.0f);
	Point b(3.0f, 3.0f);
	Point check(3.0f , 2.0f);

	std::cout << "result:" << checkPoint(b,a,check) << std::endl;

    return (0);
}