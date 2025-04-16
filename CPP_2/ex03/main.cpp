#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

int main (void)
{
    Point test(12.3f, 14.5);

    std::cout << "test:" << test.getXvalue() << std::endl;

    return (0);
}