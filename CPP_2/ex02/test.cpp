#include <iostream>
#include <cmath>

	int main(void)
{
	int x = roundf(4.3 * 256);
	int y = roundf(2.5 * 256);
	float f = (float)x / y;
	int result = roundf( f * 256);
	std::cout << "x:" << x << std::endl;
	std::cout << "y:" << y <<  std::endl;
	
	// float y = (float)(x+2) / 256;
	// std::cout << "x:" <<(double) 315906 / 256  << std::endl;
	std::cout.precision(5);
	// std::cout << "f:" << f <<  std::endl;
	std::cout << std::fixed << result << std::endl;
	std::cout << std::fixed << (float)result / 256<< std::endl;
	
}
// }

// int main () {
// 	double a = 1234.003906;
// 	double b = 2006.0;
// 	double c = 1.0e-10;
  
// 	std::cout.precision(5);
  
// 	std::cout << "default:\n";
// 	std::cout << a << '\n' << b << '\n' << c << '\n';
  
// 	std::cout << '\n';
  
// 	std::cout << "fixed:\n" << std::fixed;
// 	std::cout << a << '\n' << b << '\n' << c << '\n';
  
// 	std::cout << '\n';
  
// 	std::cout << "scientific:\n" << std::scientific;
// 	std::cout << a << '\n' << b << '\n' << c << '\n';
// 	return 0;
//   }