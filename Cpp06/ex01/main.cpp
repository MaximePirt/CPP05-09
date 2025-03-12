
#include "Serializer.hpp"


int main()
{
	Data test;

	test.int_data = 42;
	test.float_data = 13.37;
	test.str = "randomstringtobetest";


	uintptr_t var = Serializer::serialize(&test);
	std::cout << "After serialize" << std::endl;
	std::cout << test.int_data << "\n";
	std::cout << test.float_data << "\n";
	std::cout << test.str << "\n";


	Data *data = Serializer::deserialize(var);
	std::cout << "After deserialize" << std::endl;
	std::cout << data->int_data << "\n";
	std::cout << data->float_data << "\n";
	std::cout << data->str << "\n";

	std::cout << "END TESTS" << std::endl;
}
