#pragma once
#include "iostream"

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;
	private:
		int					_fixedPointValue;
		static const int	_numberOfFractionalBits = 8;
};
