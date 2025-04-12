#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& scr);
		
		Fixed& 	operator=(const Fixed& scr);
		int		getRawBits(void)const;
		void	setRawBits(int const raw);

	private:
		static const int	_fractionalBits = 8;
		int					_fixedPoint;
};
