#include <iostream>
#include "bigint.hpp"

int main() {
    // Création de Bigints
    Bigint num1("242"), num2("10"), num3, num4(100);
    Bigint num5 = num2;
    const Bigint numC(60);

    // Test des opérateurs arithmétiques
    std::cout << num1 << num2 << num3 << num4 << num5 << numC << std::endl;
    std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
    num3 = num1;
    num3 += num2;
    std::cout << "num3 += num2: " << num3 << std::endl;

    Bigint num8("999"), num9("999");
    
    // Test des comparaisons
    std::cout << "num8 == num9: " << (num8 == num9) << std::endl;
    std::cout << "num8 != num9: " << (num8 != num9) << std::endl;
    std::cout << "num8 < num9: " << (num8 < num9) << std::endl;
    std::cout << "num8 <= num9: " << (num8 <= num9) << std::endl;
    std::cout << "num8 > num9: " << (num8 > num9) << std::endl;
    std::cout << "num8 >= num9: " << (num8 >= num9) << std::endl;

    Bigint num10("4254");
    // Test des décalages avec entiers
    std::cout << "num10 << 2 = " << (num10 << 2) << std::endl;
    std::cout << "num10 >> 2 = " << (num10 >> 3) << std::endl;

    Bigint num11("2");
    // // Test des décalages avec Bigint
    std::cout << "num1 << num5 = " << (num10 >> num11) << std::endl;
    std::cout << "num1 >> num5 = " << (num10 << num11) << std::endl;

    Bigint num12("2");
    // // Test des décalages avec Bigint
    std::cout << "num1 << num5 = " << (num12++) << std::endl;
    std::cout << "num1 >> num5 = " << (++num10) << std::endl;


    // Test des décalages avec Bigint constant
    std::cout << "num1 << numC = " << (num10 << numC) << std::endl;
    std::cout << "num1 >> numC = " << (num10 >> numC) << std::endl;

    // Test des affectations combinées avec décalages
    num3 = num1;
    num3 <<= 2;
    std::cout << "num3 <<= 2: " << num3 << std::endl;
    num3 >>= 1;
    std::cout << "num3 >>= 1: " << num3 << std::endl;

    // Test des affectations combinées avec Bigint
    num3 = num1;
    num3 <<= num5;
    std::cout << "num3 <<= num5: " << num3 << std::endl;
    num3 >>= num5;
    std::cout << "num3 >>= num5: " << num3 << std::endl;

    return 0;
}