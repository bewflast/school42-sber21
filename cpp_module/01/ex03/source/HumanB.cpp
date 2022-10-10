#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack()
{
    
    std::cout   <<  this->_name                 << 
                    " attacks with their "      << 
                    this->_weapon->getType()    << 
                    std::endl;
}