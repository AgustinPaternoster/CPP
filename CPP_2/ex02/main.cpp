#include "Fixed.hpp"
#include <iostream>

int	main( void ) {



Fixed 	const b( 42.420f );
Fixed 	const c( 42.424f );

// if (b > c)
// 	std::cout << "OK" << std::endl;
// if (b < c)
	std::cout << b << std::endl;
// else
	std::cout << c << std::endl;

return 0;
}