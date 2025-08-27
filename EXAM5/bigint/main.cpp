#include "bigint.hpp"
#include <iostream>

int main(void)
{
    Bigint a(1337);
    Bigint b("10");


    

    std::cout << (a >> 5) << std::endl;
    // std::cout << a.getNumber()<< std::endl;
}