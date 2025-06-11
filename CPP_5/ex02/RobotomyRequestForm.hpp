#ifndef __RRF_H__
#define  __RRF_H__
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		std::string getTarget(void)const;
		void executeAction(void)const;

		private:
			const std::string _target;
};

#endif