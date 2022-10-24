#include "ScavTrap.hpp"

ScavTrap::~ScavTrap()
{
    std::cout   <<  "ScavTrap " <<  this->_name <<  " was destroyed!"   <<  std::endl;
}

ScavTrap::ScavTrap( const std::string name )
:
    ClapTrap(name)
{
    this->_hitPoints    = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout   <<  "ScavTrap " <<  this->_name <<  " conversion constructor was called!"   <<  std::endl;
};

ScavTrap::ScavTrap( void )
:
    ClapTrap()
{
    this->_hitPoints    = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
};

ScavTrap::ScavTrap( const ScavTrap& other )
:
    ClapTrap(other)
{
    this->_hitPoints    = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;    
    std::cout   <<  "ScavTrap " <<  this->_name <<  " copy constructor was called!"   <<  std::endl;
};

ScavTrap&   ScavTrap::operator=( const ScavTrap& other )
{
    this->_hitPoints    = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_name         = other._name;

    std::cout   <<  "ScavTrap " <<  this->_name <<  " copy assignment was called!"   <<  std::endl;

    return (*this);
};

void    ScavTrap::attack( const std::string& name )
{
    if (!this->_hitPoints || !this->_energyPoints)
    {
        std::cout   <<  "ScavTrap "  <<  this->_name        <<  
                    " has no "                              << 
                    (!this->_hitPoints ? "hit" :  "energy") << 
                    " points left to attack "               << 
                    name << std::endl;
        return;
    }

    std::cout       <<  "ScavTrap " <<  this->_name         <<  
                    " attacks "     <<  name                <<
                    ", causing "    <<  this->_attackDamage <<
                    " points of damage!"    <<  std::endl   ;
    
    this->_energyPoints--;
}

void    ScavTrap::guardGate( void ) const
{
    std::cout       <<  "ScavTrap " <<  this->_name         <<
                    " is now in Gate keeper mode"           <<
                    std::endl                               ;
}