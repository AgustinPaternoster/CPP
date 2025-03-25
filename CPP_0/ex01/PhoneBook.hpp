#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

 #include <iostream>
 #include "Contact.hpp"
 
 class PhoneBook 
 {
	
	 public:
	 
	 PhoneBook(void):contacts(0){};
	 
	 void add(void);
	 void search(void);

	 private:
	 
	 	int contacts;
	 	Contact contactos[8];

		void validate_index(int index);

 };

#endif