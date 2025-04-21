#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_fixedPoint = 0;
};

Fixed::Fixed(const int i_nb)
{
	_fixedPoint = i_nb * 256;
}

Fixed::Fixed(const float f_nb)
{
	_fixedPoint = roundf(f_nb * 256);
}

Fixed::~Fixed(void){};

Fixed::Fixed(const Fixed& scr)
{
	if (&scr != this)
	{
		*this = scr;
	}
};

Fixed& Fixed::operator=(const Fixed& scr)
{
	if (&scr != this)
	{
		this->_fixedPoint = scr.getRawBits();
	}
	return (*this);
};

Fixed Fixed::operator+(const Fixed& src)const
{
	Fixed tmp;
	tmp.setRawBits(this->_fixedPoint + src._fixedPoint);
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& src)const
{
	Fixed tmp;
	tmp.setRawBits(this->_fixedPoint - src._fixedPoint);
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& src)const
{
	Fixed tmp;
	int result = (this->_fixedPoint * src._fixedPoint) / 256 ;
	tmp.setRawBits(result);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& src)const
{
	Fixed tmp;
	float result = (float)this->_fixedPoint / src._fixedPoint;
	tmp.setRawBits(roundf(result * 256));
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

Fixed& Fixed::operator++(void)
{
	this->_fixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_fixedPoint++;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	this->_fixedPoint--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_fixedPoint--;
	return (tmp);
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

const Fixed&	Fixed::min(const Fixed& numA , const Fixed& numB)
{
	if (numA <= numB)
		return (numA);
	else
		return(numB);
}

Fixed&	Fixed::min(Fixed& numA , Fixed& numB)
{
	if (numA <= numB)
		return (numA);
	else
		return(numB);
}

const Fixed&	Fixed::max(const Fixed& numA , const Fixed& numB)
{
	if (numA >= numB)
		return (numA);
	else
		return(numB);
}

Fixed&	Fixed::max(Fixed& numA , Fixed& numB)
{
	if (numA >= numB)
		return (numA);
	else
		return(numB);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rsc)
{
	o << rsc.toFloat();
	return o;
}