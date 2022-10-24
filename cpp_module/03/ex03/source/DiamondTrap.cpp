#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
    std::cout   <<  "DiamondTrap " <<  this->_name <<  " was destroyed!"   <<  std::endl;
}

DiamondTrap::DiamondTrap( const std::string name )
:   
    ClapTrap(name + "_clap_name"),
    ScavTrap(name + "_clap_name"),
    FragTrap(name + "_clap_name"),
    _name(name)
{
    this->_energyPoints = 50;
    std::cout   <<  "DiamondTrap " <<  this->_name <<  " conversion constructor was called!"   <<  std::endl;
};

DiamondTrap::DiamondTrap( void )
:
    ClapTrap(),
    ScavTrap(),
    FragTrap(),
    _name("undef")
{
    this->_energyPoints     = 50;
    this->ClapTrap::_name   = "undef_clap_name";
};

DiamondTrap::DiamondTrap( const DiamondTrap& other )
:
    ClapTrap(other),
    ScavTrap(other),
    FragTrap(other)
{
    this->_name             = other._name;
    this->ClapTrap::_name   = _name + "_clap_name";

    this->_energyPoints     = 50;    

    std::cout   <<  "DiamondTrap " <<  this->_name <<  " copy constructor was called!"   <<  std::endl;
};

DiamondTrap&   DiamondTrap::operator=( const DiamondTrap& other )
{
    dynamic_cast<FragTrap&>(*this) = other;
    this->ClapTrap::_name = other._name + "_clap_name";

    std::cout   <<  "DiamondTrap " <<  this->_name <<  " copy assignment was called!"   <<  std::endl;

    return (*this);
};

void    DiamondTrap::attack( const std::string& name )
{
    if (!this->_hitPoints || !this->_energyPoints)
    {
        std::cout   <<  "DiamondTrap "  <<  this->_name     <<  
                    " has no "                              << 
                    (!this->_hitPoints ? "hit" :  "energy") << 
                    " points left to attack "               << 
                    name << std::endl;
        return;
    }

    std::cout       <<  "DiamondTrap " <<  this->_name      <<  
                    " attacks "     <<  name                <<
                    ", causing "    <<  this->_attackDamage <<
                    " points of damage!"    <<  std::endl   ;
    
    this->_energyPoints--;
}
