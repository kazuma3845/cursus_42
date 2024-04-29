# pragma once

# include <iostream>

template <class T> class Array
{
	private:
		int aray[];
	public:
		Array() {};
		Array(unsigned int n) {
			aray[n];
		};
		Array(T &f) {(void)f;return *this;};
		T &opreator=(T &f) {(void)f;return *this;};
		~Array() {};


};