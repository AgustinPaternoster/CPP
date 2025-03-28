#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

 #include <iostream>
 #include "Contact.hpp"
 #include <limits>
 class PhoneBook 
 {
	 public:
	 
	 PhoneBook(void);
	 ~PhoneBook(void);
	 void add(void);
	 void search(void);
	 void print_intructions(void);
	 
	 private:
	 
	 	void move_contacts(int contacts);
	 	int 	_contacts;
	 	Contact _contact_list[8];
 };

#endif