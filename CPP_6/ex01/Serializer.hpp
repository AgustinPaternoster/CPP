#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <iostream>
#include <cctype>
#include <stdint.h>

struct Data
{
	int nb;
	std::string txt;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		~Serializer(void);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

std::ostream& operator<<(std::ostream &os, const Data& other);

#endif