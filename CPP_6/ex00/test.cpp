#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <iomanip>

int main() {
    
	long i = -100;
	float t = std::numeric_limits<float>::min() ;
	
	if (t > static_cast<float>(i))
		std::cout << "ok" << std::endl;
	else
		std::cout << "no" << std::endl;

	std::cout << t << std::endl;
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(i) << std::endl;
	return 0;
}

