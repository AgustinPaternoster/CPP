#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed& scr)
{
	if (&scr != this)
	{
		std::cout << "Copy contructor called" << std::endl;
		*this = scr;
	}
};

Fixed& Fixed::operator=(const Fixed& scr)
{
	if (&scr != this)
	{
		
		std::cout << "Copy assignment operator called" << std::endl;
		_fixedPoint = scr.getRawBits();
	}
	return (*this);
};

int Fixed::getRawBits(void)const
{
	std::cout << "getRawsBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits(const int raw)
{
	_fixedPoint = raw;
}