#include "Serializer.hpp"

// Constructor and destructor

Serializer::Serializer(){

}

Serializer::Serializer(const Serializer &obj)
{
	*this = obj;
}

Serializer &Serializer::operator=(const Serializer &old)
{
	(void)old;
	return (*this);
}

Serializer::~Serializer()
{

}

//functions

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));

}