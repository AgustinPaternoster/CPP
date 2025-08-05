#ifndef __WARLOCK_H__
#define __WARLOCK_H__
#include <string>

class Warlock
{
	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);

		const std::string& getName(void)const;
		const std::string& getTitle(void)const;

		void setTitle(const std::string& title);
		void introduce(void)const;

	private:
		std::string _name;
		std::string _title;
};

#endif