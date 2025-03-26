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
			if (data_contact[i].empty() == 0)
				break;
			else
			   std::cout << "No ha ingresado ningun valor" << std::endl;
		}
	}
	move_contacts(contacts);
	contactos[0].new_contact(data_contact[0],
							 data_contact[1],
							 data_contact[2],
							 data_contact[3]);
    
	if(this->contacts < 8)
		this->contacts++;
	std::cout << "** Contacto creado **" << std::endl;
}

void PhoneBook::search(void)
{
    int index;

	if (contacts == 0)
		std::cout << "No hay ningun registro" << std::endl;
	else
	{
		std::cout << "Ingrese el indice del contacto: ";
		std::cin >> index;
		while(index > this->contacts || index == 0 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "indice incorrecto " << "hay "<< contacts 
						<< " contactos registrados :";
			std::cin >> index;	
		}
		this->contactos[index - 1].print_data();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void PhoneBook::print_intructions(void)
{
	std::cout << "Ingrese  ADD para agregar un contacto" << std::endl;
	std::cout << "Ingrese  SEARCH para buscar un contacto" << std::endl;
	std::cout << "Ingrese  EXIT para salir de la aplicacion" << std::endl;
}

void PhoneBook::move_contacts(int contacts)
{	
	for (int i = contacts ; i > 0; i--)
	{
		if (i < 8)
			contactos[i] = contactos[i - 1];
	}
}

// {
// 	std::string text = "01234567891";
// 	if (text.size() > 10)
// 		std::cout << std::setfill('.') << std::setw(10) << std::left << text.substr(0,9) << "|" << std::endl;
// 	else
// 		std::cout << std::setw(10) << text << "|" << std::endl;
// 	return(0);
// }