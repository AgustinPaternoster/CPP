#ifndef __WEAPON_HPP__
 #define __WEAPON_HPP__	
 #include <string>

 class Weapon
{
	public:

	Weapon(std::string type);
	Weapon(Weapon const &rsc);
	~Weapon(void);

	Weapon & operator=(Weapon const &rsc);
	
	std::string const & getType(void);
	void setType(std::string type);
	
	private:

	std::string _type;

};

#endif