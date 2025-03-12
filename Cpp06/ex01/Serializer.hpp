#ifndef SERIALIZER_HPP
	#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>


struct Data
{
	int int_data;
	float float_data;
	std::string str;
};

class Serializer{
	private:
		Serializer();
		Serializer(const Serializer &obj);
		Serializer &operator=(const Serializer &old);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};


#endif