#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    DiamondTrap( void );

    std::string _name;

public:
    ~DiamondTrap();
    DiamondTrap( std::string );
    DiamondTrap( const DiamondTrap& );

    DiamondTrap& operator=( const DiamondTrap& );

    void attack( const std::string& );
};

#endif