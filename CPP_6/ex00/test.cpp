#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

std::string checkFloatRange(const std::string& input) {
    try {
        // Convertimos el string a long double para preservar la magnitud
        long double value = std::stold(input);

        // if (value >= -std::numeric_limits<float>::max() &&
        //     value <= std::numeric_limits<float>::max()) {
        //     return "dentro";
        // } else {
        //     return "fuera";
        // }
		 if (value >= -std::numeric_limits<int>::max() &&
            value <= std::numeric_limits<int>::max()) {
            return "dentro";
        } else {
            return "fuera";
        }

    } catch (const std::exception& e) {
        // En caso de que el string no sea un número válido
        return "err";
    }
}



int main(int arc, char**argv) {
    
	std::string test = argv[1];
	std::cout << checkFloatRange(test) << std::endl;
	return 0;
}

