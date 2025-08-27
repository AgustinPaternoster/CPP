#include "bigint.hpp"
#include <iostream>

int main(void)
{
    Bigint a(234);
    Bigint b("10");
    Bigint c;

    b += a;
    std::cout << b << std::endl;
    // std::cout << a.getNumber()<< std::endl;
}