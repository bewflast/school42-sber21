#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
    HumanA();

    std::string _name;
    Weapon&      _weapon;

public:
    HumanA(std::string name, Weapon& weapon)
    :
        _name(name),
        _weapon(weapon)
    {};

    void    setWeapon(Weapon& weapon);

    void    attack();
};

#endif