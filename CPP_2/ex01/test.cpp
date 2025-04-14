#include <cmath>
#include <iostream>

float divided(int x)
{
	return (std::round(x / 256.0));
}

int main(void)
{
	int x = std::roundf(1234.4321 * 256);
	int y = 1234.4321 * 256;
	std::cout << "x:" << x  << std::endl;
	std::cout << "y:" << y  << std::endl;
	std::cout << "-x:" << divided(x) << std::endl;
	std::cout << "-y:" <<(float) y / 256  << std::endl;


	return (0);

}