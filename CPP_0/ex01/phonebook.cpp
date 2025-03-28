#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void):_contacts(0)
{
	std::cout << "---PHONEBOOK APP STARTED---" << std::endl;
}
PhoneBook::~PhoneBook(void)
{
	std::cout << "---PHONEBOOK APP ENDED---" << std::endl;
}
void PhoneBook::add(void)
{
	std::string data[] = {"First Name", "Last Name", "nickname" , "phone number"}; 
	std::string data_contact[4];

	for (int i = 0 ; i < 4 ; i++)
	{
		while(1)
		{
			std::cout << "Enter " << data[i] << ": ";
			std::getline(std::cin , data_contact[i]);			
			if (data_contact[i].empty() == 0)
				break;
			else
			   std::cout << "No data has been entered" << std::endl;
		}
	}
	move_contacts(_contacts);
	_contact_list[0].new_contact(data_contact[0],
							 data_contact[1],
							 data_contact[2],
							 data_contact[3]);
    
	if(this->_contacts < 8)
		this->_contacts++;
	std::cout << "** Contact created **" << std::endl;
}

void PhoneBook::search(void)
{
    int index;

	if (_contacts == 0)
		std::cout << "There is no record" << std::endl;
	else
	{
		std::cout << "Enter index's contact: ";
		std::cin >> index;
		while(index > this->_contacts || index == 0 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong index " << "There are "<< _contacts 
						<< " registred contacts:";
			std::cin >> index;	
		}
		this->_contact_list[index - 1].print_data();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void PhoneBook::print_intructions(void)
{
	std::cout << "Enter  ADD to add a contact" << std::endl;
	std::cout << "enter  SEARCH to search a contact" << std::endl;
	std::cout << "Enter  EXIT exit the app" << std::endl;
}

void PhoneBook::move_contacts(int contacts)
{	
	for (int i = contacts ; i > 0; i--)
	{
		if (i < 8)
			_contact_list[i] = _contact_list[i - 1];
	}
}
