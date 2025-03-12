
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

	// int type = find_type(argv[1]);
	// switch (type){
	// 	case 0:
	// 		std::cout << "result CHAR" << std::endl;
	// 		break ;
	// 	case 1:
	// 		std::cout << "result INT" << std::endl;
	// 		break ;
	// 	case 2:
	// 		std::cout << "result FLOAT" << std::endl;
	// 		break ;
	// 	case 3:
	// 		std::cout << "result DOUBLE" << std::endl;
	// 		break ;
	// 	case 4:
	// 		std::cout << "result ZERO" << std::endl;
	// 		break ;
	// 	case 5:
	// 		std::cout << "result ERROR" << std::endl;
	// }

    return 0;
}
