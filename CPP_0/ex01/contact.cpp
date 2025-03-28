#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

void Contact::new_contact(std::string fn, std::string ln, std::string nn, std::string pn)
{
	this->_first_name = fn;
	this->_last_name = ln;
	this->_nick_name = nn;
	this->_phone_number	= pn;
}
void Contact::print_data(void)
{
	std::string array[4] = {_first_name, _last_name, _nick_name, _phone_number};
	std::cout << '|';
	for (int i = 0; i < 4; i++)
	{
		if (array[i].size() > 10)
			 std::cout << std::setfill('.') << std::setw(10) << std::left << array[i].substr(0,9) << "|";
		else
			std::cout << std::setw(10) << std::setfill(' ') << std::right << array[i] << "|";
	}
	std::cout << std::endl;
}
