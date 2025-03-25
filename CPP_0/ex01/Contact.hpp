#ifndef CONTACT_HPP
 #define CONTACT_HPP
 #include <iostream>

class Contact
{
	 
	public:
		 int 		index;

		 Contact(void)
		 {
			std::cout << "Contacto iniciado" << std::endl;
		 }
		 
		 void new_contact(int index, std::string fn, std::string ln, std::string nn, std::string pn)
		 {
			this->index 		= index;
			this->first_name 	= fn;
			this->last_name		= ln;
			this->nick_name		= nn;
			this->phone_number	= pn;
		 }
	private:
	 
		std::string first_name;
		std::string last_name;
		std::string	nick_name;
		std::string phone_number; 
};

#endif