
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
		Fixed	operator+(const Fixed& scr)const;
		Fixed	operator-(const Fixed& scr)const;
		Fixed	operator*(const Fixed& scr)const;
		Fixed	operator/(const Fixed& scr)const;
		bool 	operator<(const Fixed& src)const;
		bool 	operator>(const Fixed& src)const;
		bool 	operator>=(const Fixed& src)const;
		bool 	operator<=(const Fixed& src)const;
		bool 	operator==(const Fixed& src)const;
		bool 	operator!=(const Fixed& src)const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static const Fixed&	min(const Fixed& numA , const Fixed& numB1);
		static 	Fixed&	min(Fixed& numA , Fixed& numB1);
		static const Fixed&	max(const Fixed& numA , const Fixed& numB1);
		static 	Fixed&	max(Fixed& numA , Fixed& numB1);

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
