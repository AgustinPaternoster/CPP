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
		   std::cout << "Ingrese el " << data[i] ;
		   //std::getline(std::cin , data_contact[i]);
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
}



int main(void)
{
    std::string command;
	PhoneBook phonebook;
    
    while (1)
    {
        std::cin >> command;
        if (command.compare("EXIT") == 0)
            break;
		if (command.compare("ADD") == 0)
			phonebook.add();
		// if (command.compare("SEARCH") == 0)
			//COMPLETAR	
		else
		{
			std::cout << "Ingrese  ADD para agregar un contacto" << std::endl;
			std::cout << "Ingrese  SEARCH para buscar un contacto" << std::endl;
			std::cout << "Ingrese  EXIT para salir de la aplicacion" << std::endl;
		}
    }
    return (0);
}