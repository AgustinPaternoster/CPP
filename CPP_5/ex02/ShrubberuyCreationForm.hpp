#ifndef __SCF_H__
#define __SCF_H__
#include "AForm.hpp"
#include <string>

class ShrubberuyCreationForm: public AForm
{
	public:
		ShrubberuyCreationForm(std::string target);
		ShrubberuyCreationForm(const ShrubberuyCreationForm & other);
		~ShrubberuyCreationForm(void);

		ShrubberuyCreationForm& operator=(const ShrubberuyCreationForm& other);
		std::string getTarget(void)const;
		void executeAction(void) const;

	private:
		const std::string _target;
};

#endif