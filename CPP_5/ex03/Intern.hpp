#ifndef __INTERN_H__
#define __INTERN_H__
#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		// Intern(const Intern& other);
		~Intern(void);

		// Intern& operator=(const Intern& other);
		AForm* makeForm(std::string name, std::string target);
	private:
		std::string _namesForm[3];
};

#endif