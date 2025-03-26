#ifndef CONTACT_HPP
 #define CONTACT_HPP
 #include <iostream>

class Contact
{
	public:		 
		
		void new_contact(std::string fn, std::string ln, std::string nn, std::string pn);
		void print_data(void);
	private:
	 
		std::string first_name;
		std::string last_name;
		std::string	nick_name;
		std::string phone_number; 
};

#endif