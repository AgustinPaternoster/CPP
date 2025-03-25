#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::add(void)
{
	std::string data[] = {"First Name", "Last Name", "nickname" , "phone number"}; 
	std::string data_contact[4];

	for (int i = 0 ; i < 4 ; i++)
	{
		while(1)
		{
			std::cout << "Ingrese el " << data[i] << ": ";
			std::getline(std::cin , data_contact[i]);
			std::cin >> data_contact[i];
			if (data_contact[i].empty() == 0)
				break;
			else
			   std::cout << "No ha ingresado ningun valor" << std::endl;
		}
	}
	contactos[contacts].new_contact(contacts,
								   data_contact[0],
								   data_contact[1],
								   data_contact[2],
								   data_contact[3]);
    this->contacts++;
	std::cout << "Contacto creado" << std::endl;
}

void PhoneBook::search(void)
{
    int index;

    std::cout << "Ingrese el indice del contacto: ";
    std::cin >> index;
    this->contactos[index].get_name();
}

void PhoneBook::validate_index(int index)
{
    if (index => this-> contacts)
    {
        std::cout << "wrong index , try again" << std::endl;
    }
}