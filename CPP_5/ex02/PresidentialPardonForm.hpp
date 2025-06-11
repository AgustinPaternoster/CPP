#ifndef __PPF_H__
#define __PPF_H__
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & other);
		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		std::string getTarget(void)const;
		void executeAction(void) const;

	private:
		const std::string _target;
};

#endif