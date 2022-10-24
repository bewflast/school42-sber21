#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
    std::cout   <<  "FragTrap " <<  this->_name <<  " was destroyed!"   <<  std::endl;
}

FragTrap::FragTrap( const std::string name )
:
    ClapTrap(name)
{
    this->_hitPoints    = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout   <<  "FragTrap " <<  this->_name <<  " conversion constructor was called!"   <<  std::endl;
};

FragTrap::FragTrap( void )
:
    ClapTrap()
{
    this->_hitPoints    = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
};

FragTrap::FragTrap( const FragTrap& other )
:
    ClapTrap(other)
{
    this->_hitPoints    = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;    
    std::cout   <<  "FragTrap " <<  this->_name <<  " copy constructor was called!"   <<  std::endl;
};

FragTrap&   FragTrap::operator=( const FragTrap& other )
{
    this->_hitPoints    = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_name         = other._name;

    std::cout   <<  "FragTrap " <<  this->_name <<  " copy assignment was called!"   <<  std::endl;

    return (*this);
};

void    FragTrap::attack( const std::string& name )
{
    if (!this->_hitPoints || !this->_energyPoints)
    {
        std::cout   <<  "FragTrap "  <<  this->_name        <<  
                    " has no "                              << 
                    (!this->_hitPoints ? "hit" :  "energy") << 
                    " points left to attack "               << 
                    name << std::endl;
        return;
    }

    std::cout       <<  "FragTrap " <<  this->_name         <<  
                    " attacks "     <<  name                <<
                    ", causing "    <<  this->_attackDamage <<
                    " points of damage!"    <<  std::endl   ;
    
    this->_energyPoints--;
}

void    FragTrap::highFivesGuys( void ) const
{
    std::cout       <<  "FragTrap " <<  this->_name         <<
                    " positively requests  high fives "     <<
                    std::endl                               ;
}