#pragma once
#include <iostream>
#include <cmath>
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

		// The 6 comparison operators: >, <, >=, <=, ==, and !=
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// The 4 arithmetic operators: +, -, *, and /.
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		// The 4 increment/decrement.
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

	private:
		int					_fixedPointValue;
		static const int	_numberOfFractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);
