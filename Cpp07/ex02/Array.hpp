#ifndef ARRAY_HPP
	#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *_elements;
		unsigned int _len;

	public:
		Array()
		{
			this->_elements = NULL;
			this->_len = 0;
		}
		Array (unsigned int n) : _len(n)
		{
			try {
				this->_elements = new T[n];
				for (unsigned int i = 0; i < n; i++)
					this->_elements[i] = T();
			}
			catch(const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
				exit (1);
			}
		}
		Array(const Array &obj)
		{
			*this = obj;
		}
		Array &operator=(const Array &old)
		{
			if (this != &old)
			{
				if (this->_elements)
				{
						delete [] this->_elements;
						this->_elements = NULL;
				}
				this->_elements = new T[old._len];
				this->_len = old._len;
				for (unsigned int i = 0; i < _len; i++)
					this->_elements[i] = old._elements[i];
			}
			return (*this);
		}
		T &operator[](const unsigned int index) const
		{
			if (index > this->_len)
				throw std::out_of_range("An error occurs. Index too long for array length.");
			return (this->_elements[index]);
		}
		unsigned int size()
		{
			return (this->_len);
		}
		~Array()
		{
			delete []this->_elements;
		}

};


#endif
