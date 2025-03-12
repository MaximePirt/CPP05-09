
#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
	try {
		if (argc != 2)
			throw ("Error, program only takes one argument");
		std::string tmp = argv[1];
		ScalarConverter::convert(tmp);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const char *msg)
	{
		std::cerr << msg << std::endl;
	}
    return 0;
}
