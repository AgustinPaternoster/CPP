#include "Serializer.hpp"
#include <exception>

uintptr_t Serializer::serialize(Data *ptr)
{
	if (ptr == NULL)
		throw "Error: NULL pointer";
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	
	return(reinterpret_cast<Data*>(raw));
}

std::ostream& operator<<(std::ostream& os , const Data& other)
{
	os << "nb: " << other.nb << std::endl << "txt: " << other.txt;
	return os;
}