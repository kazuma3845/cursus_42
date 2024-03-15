#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed(const int i);
		Fixed(const float i);
		Fixed( const Fixed &f );
		Fixed &operator=(const Fixed &f);
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int _i;
		static const int _v = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
