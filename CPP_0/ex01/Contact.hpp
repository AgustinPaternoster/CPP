#ifndef CONTACT_HPP
 #define CONTACT_HPP
 #include <iostream>

class Contact
{
	public:		 
		
		void new_contact(std::string fn, std::string ln, std::string nn, std::string pn);
		void print_data(void);
	private:
	 
		std::string _first_name;
		std::string _last_name;
		std::string	_nick_name;
		std::string _phone_number; 
};

#endif