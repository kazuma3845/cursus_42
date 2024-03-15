#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed(const int i);
		Fixed(const float i);
		Fixed( const Fixed &f );
		Fixed &operator=(const Fixed &f);
	
		Fixed operator+(const Fixed &f) const;
		Fixed operator-(const Fixed &f) const;
		Fixed operator*(const Fixed &f) const;
		Fixed operator/(const Fixed &f) const;
	
		bool operator>(const Fixed &f) const;
		bool operator<(const Fixed &f) const;
		bool operator>=(const Fixed &f) const;
		bool operator<=(const Fixed &f) const;
		bool operator==(const Fixed &f) const;
		bool operator!=(const Fixed &f) const;


		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	private:
		int _i;
		static const int _v = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif
