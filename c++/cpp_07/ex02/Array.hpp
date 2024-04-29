# pragma once

template <typename T> class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array() : _size(0) {this->_array = new T[this->_size];}
		Array(unsigned int n) : _size(n) {this->_array = new T[this->_size];}
		Array(const Array &f) : _size(f._size) {this->_array = NULL;*this = f;}
		~Array() {if (this->_array != NULL) delete[] this->_array;}

		Array &operator=(const Array &f)
		{
			if (this->_array != NULL)
				delete[] this->_array;
			if (f.size() != 0)
			{
				this->_size = f.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_array[i] = f._array[i];
			}
			return *this;
		}

		T &operator[](unsigned int i)
		{
			if (i >= this->_size || this->_array == NULL)
				throw std::exception();
			return this->_array[i];
		};

		unsigned int size() const
		{
			return this->_size;
		}
};
