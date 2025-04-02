#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	try {
		if (argc != 2)
			throw std::out_of_range("Input errors, Program must have 1 arguments");
		RPN programLaunch;
		programLaunch.Calculate(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

