#include "Fixed.hpp"

Fixed::Fixed() :
			_fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _numberOfFractionalBits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _numberOfFractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

int		Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> this->_numberOfFractionalBits);
}
float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPointValue / (1 << this->_numberOfFractionalBits));
}

// The 6 comparison operators: >, <, >=, <=, ==, and !=
bool	Fixed::operator>(const Fixed &other) const
{
	return this->_fixedPointValue > other.getRawBits();
}
bool	Fixed::operator<(const Fixed &other) const
{
	return this->_fixedPointValue < other.getRawBits();
}
bool	Fixed::operator>=(const Fixed &other) const
{
	return this->_fixedPointValue >= other.getRawBits();
}
bool	Fixed::operator<=(const Fixed &other) const
{
	return this->_fixedPointValue <= other.getRawBits();
}
bool	Fixed::operator==(const Fixed &other) const
{
	return this->_fixedPointValue == other.getRawBits();
}
bool	Fixed::operator!=(const Fixed &other) const
{
	return this->_fixedPointValue != other.getRawBits();
}

// The 4 arithmetic operators: +, -, *, and /.
Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed	Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// The 4 increment/decrement.
Fixed	&Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}
Fixed	&Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return tmp;
}
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return tmp;
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
