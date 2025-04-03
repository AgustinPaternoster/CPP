#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__
#include <string>
#include "Weapon.hpp"

class HumanB
{
    public:

        HumanB(std::string name);
        HumanB(HumanB const & rsc);
        ~HumanB(void);

        void attack(void);
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon *weapon;
};

#endif