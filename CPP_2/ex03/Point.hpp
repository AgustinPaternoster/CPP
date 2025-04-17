#ifndef __POINT_H__
#define __POINT_H__

#include "Fixed.hpp"
#include <string>

class Point
{
    public:
        Point(void);
        Point(const float x , const float y);
       	Point(const Point& rsc);
        ~Point(void);

        Point& operator=(const Point& rsc);
        const Fixed& getX(void)const;
        const Fixed& getY(void)const;

    private:
        const Fixed _x;
        const Fixed _y; 
};

#endif