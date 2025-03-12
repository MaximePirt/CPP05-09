
#include "Serializer.hpp"


int main()
{
	Data ptr;

	ptr.int_data = 42;
	ptr.float_data = 13.37;
	ptr.str = "login";
	uintptr_t var = Serializer::serialize(&ptr);
	std::cout << "After serialize" << std::endl;
	std::cout << ptr.int_data << "\n";
	std::cout << ptr.float_data << "\n";
	std::cout << ptr.str << "\n";
	Data *data = Serializer::deserialize(var);
	std::cout << "After deserialize" << std::endl;
	std::cout << data->int_data << "\n";
	std::cout << data->float_data << "\n";
	std::cout << data->str << "\n";
}
