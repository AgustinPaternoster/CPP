
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int i_nb);
		Fixed(const float f_nb);
		~Fixed(void);
		Fixed(const Fixed& scr);
		

		Fixed& 	operator=(const Fixed& scr);
		Fixed	operator+(const Fixed& scr);
		Fixed	operator-(const Fixed& scr);
		Fixed	operator*(const Fixed& scr);
		Fixed	operator/(const Fixed& scr);
		bool 	operator<(const Fixed& src)const;
		bool 	operator>(const Fixed& src)const;
		bool 	operator>=(const Fixed& src)const;
		bool 	operator<=(const Fixed& src)const;
		bool 	operator==(const Fixed& src)const;
		bool 	operator!=(const Fixed& src)const;


		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		float	toFloat(void)const;
		int		toInt(void)const;

	private:
		static const int	_fractionalBits = 8;
		int					_fixedPoint;

};

std::ostream & operator<<(std::ostream & o, Fixed const & rsc);
#endif
