#ifndef __WEAPON_HPP__
 #define __WEAPON_HPP__	
 #include <string>

 class Weapon
{
	public:

	Weapon(std::string type);
	~Weapon(void);

	
	std::string const & getType(void);
	void setType(std::string type);
	
	private:

	std::string _type;

};

#endif