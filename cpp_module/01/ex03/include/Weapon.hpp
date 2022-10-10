#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    std::string _type;

public:
    Weapon(std::string type)
    :
        _type(type)
    {};

    Weapon()
    :
        _type("none")
    {};
    
    const std::string&  getType();
    void    setType(std::string new_type);
};

#endif