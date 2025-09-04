#include "bigint.hpp"
#include <iostream>

int main(void)
{
    Bigint a("0");
    Bigint b(2);
    Bigint c;
    a <<= b;

    std::cout << a << std::endl;
    // std::cout << a.getNumber()<< std::endl;
}