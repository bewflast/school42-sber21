#include "Weapon.hpp"

const std::string& Weapon::getType()
{
    return (this->_type);
}

void    Weapon::setType(std::string new_type)
{
    this->_type = new_type;
}