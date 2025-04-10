#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	try {
		if (argc != 2)
			throw std::out_of_range("Error: could not open file.");
		BitcoinExchange programLaunch;
		programLaunch.readInputFile(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
