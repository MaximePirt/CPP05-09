#ifndef SCALARCONVERTER_HPP
	#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib> 
#include <cctype>
#include <climits>
#include <cstring>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter &operator=(const ScalarConverter &old);
		~ScalarConverter();
	public:
		static void convert(std::string literal);

};


#endif