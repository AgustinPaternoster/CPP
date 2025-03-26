#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

 #include <iostream>
 #include "Contact.hpp"
 #include <limits>
 class PhoneBook 
 {
	 public:
	 
	 PhoneBook(void):contacts(0){};
	 void add(void);
	 void search(void);
	 void print_intructions(void);
	 
	 private:
	 
	 	void move_contacts(int contacts);
	 	int contacts;
	 	Contact contactos[8];
 };

#endif