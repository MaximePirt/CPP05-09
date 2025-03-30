#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	try {
		if (argc != 2)
			throw std::out_of_range("Input errors, Program must have 1 arguments");
		BitcoinExchange programLaunch;
		programLaunch.readInputFile(argv[1]);
		std::cout << "Success" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
