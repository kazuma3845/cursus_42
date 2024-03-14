#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed &f );
		Fixed &operator=(const Fixed &f);
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int _i;
		static const int _v = 8;
};

#endif
