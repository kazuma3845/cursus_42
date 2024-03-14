#include "Fixed.hpp"

Fixed::Fixed(void) : _i(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	int r = i;
	for (int j = this->_v; j > 0; j--)
		r *=2;
	this->_i = r;
}

Fixed::Fixed(const float i) : _i(i)
{
	std::cout << "Float constructor called" << std::endl;
	float r = i;
	for (int j = this->_v; j > 0; j--)
		r *=2;
	this->_i = r;
}

Fixed::Fixed(const Fixed &f) : _i(f._i)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_i = f.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_i);
}

void Fixed::setRawBits( int const raw )
{
	this->_i = raw;
}

float Fixed::toFloat( void ) const
{
	float r = this->_i;
	for (int j = this->_v; j > 0; j--)
		r /=2;
	return r;
}

int Fixed::toInt( void ) const
{
	int r = this->_i;
	for (int j = this->_v; j > 0; j--)
		r /=2;
	return r;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}

static Fixed &min(Fixed &a, Fixed &b)
{
	if (a>b)
		return (b);
	else
		return (a);
}

static Fixed &max(Fixed &a, Fixed &b)
{
	if (a<b)
		return (b);
	else
		return (a);
}

static const Fixed &min(const Fixed &a, const Fixed &b)
{
	if (a>b)
		return (b);
	else
		return (a);
}

static const Fixed &max(const Fixed &a, const Fixed &b)
{
	if (a<b)
		return (b);
	else
		return (a);
}

Fixed& Fixed::operator++(void)
{
	
}

Fixed& Fixed::operator--(void)
{

}

Fixed Fixed::operator++(int)
{

}

Fixed Fixed::operator--(int)
{

}
