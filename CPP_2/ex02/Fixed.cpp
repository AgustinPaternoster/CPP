#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
};

Fixed::Fixed(const int i_nb)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = i_nb * 256;
}

Fixed::Fixed(const float f_nb)
{
	std::cout << "float constructor called" << std::endl;
	_fixedPoint = roundf(f_nb * 256);
}

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
		this->_fixedPoint = scr.getRawBits();
	}
	return (*this);
};

Fixed Fixed::operator+(const Fixed& src)
{
	Fixed tmp;
	tmp.setRawBits(this->_fixedPoint + src._fixedPoint);
	return (tmp);
}

Fixed Fixed::operator+(const Fixed& src)
{
	Fixed tmp;
	tmp.setRawBits(this->_fixedPoint - src._fixedPoint);
	return (tmp);
}

bool Fixed::operator<(const Fixed& src)const
{
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator<=(const Fixed& src)const
{
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator>(const Fixed& src)const
{
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator>=(const Fixed& src)const
{
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator==(const Fixed& src)const
{
	return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed& src)const
{
	return (this->getRawBits() != src.getRawBits());
}

int Fixed::getRawBits(void)const
{
	return (_fixedPoint);
}

void Fixed::setRawBits(const int raw)
{
	_fixedPoint = raw;
}

int Fixed::toInt(void)const
{
	return (getRawBits() / 256);
}

float Fixed::toFloat(void)const
{
	return((float)getRawBits() / 256);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rsc)
{
	o << rsc.toFloat();
	return o;
}