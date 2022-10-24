#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
    ClapTrap();
    unsigned int         _hitPoints;
    unsigned int         _energyPoints;
    unsigned int         _attackDamage;
    std::string         _name;

public:
    ~ClapTrap();
    ClapTrap( std::string );
    ClapTrap( const ClapTrap& );
    ClapTrap& operator=( const ClapTrap& );

    void    attack( const std::string& );
    void    takeDamage( unsigned int );
    void    beRepaired( unsigned int );
};

#endif