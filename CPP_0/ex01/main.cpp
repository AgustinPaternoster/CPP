#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main(void)
{
    std::string command;
	PhoneBook phonebook;
    
	while (1)
    {
		phonebook.print_intructions();
		std::cout << "Enter a command: ";
		std::getline(std::cin , command);
        if (command.compare("EXIT") == 0)
			break;
		if (command.compare("ADD") == 0)
			phonebook.add();
		if (command.compare("SEARCH") == 0)
			phonebook.search();	
}
    return (0);
}