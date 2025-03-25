#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

 #include <iostream>
 #include "Contact.hpp"
 
 class PhoneBook 
 {
	
	 public:
	 
	 PhoneBook(void):contacts(0){};
	 
	 void add(void);

	 private:
	 
	 	int contacts;
	 	Contact contactos[8];

 };

#endif