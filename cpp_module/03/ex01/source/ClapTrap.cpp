#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
    std::cout   <<  "ClapTrap " <<  this->_name <<  " was destroyed!"   <<  std::endl;
}

ClapTrap::ClapTrap( const std::string name )
:
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0),
    _name(name)
{
    std::cout   <<  "ClapTrap " <<  this->_name <<  " conversion constructor was called!"   <<  std::endl;
};

ClapTrap::ClapTrap( void ) 
: 
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0),
    _name("undef")
{};

ClapTrap::ClapTrap( const ClapTrap& other )
:
    _hitPoints(other._hitPoints),
    _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage),
    _name(other._name)
{    
    std::cout   <<  "ClapTrap " <<  this->_name <<  " copy constructor was called!"   <<  std::endl;
};

ClapTrap&   ClapTrap::operator=( const ClapTrap& other )
{
    this->_hitPoints    = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_name         = other._name;

    std::cout   <<  "ClapTrap " <<  this->_name <<  " copy assignment was called!"   <<  std::endl;

    return (*this);
};

void    ClapTrap::attack( const std::string& name )
{
    if (!this->_hitPoints || !this->_energyPoints)
    {
        std::cout   <<  "ClapTrap "  <<  this->_name        <<  
                    " has no "                              << 
                    (!this->_hitPoints ? "hit" :  "energy") << 
                    " points left to attack "               << 
                    name << std::endl;
        return;
    }

    std::cout       <<  "ClapTrap " <<  this->_name         <<  
                    " attacks "     <<  name                <<
                    ", causing "    <<  this->_attackDamage <<
                    " points of damage!"    <<  std::endl   ;
    
    this->_energyPoints--;
}

void    ClapTrap::takeDamage( unsigned int damage )
{
    this->_hitPoints = (this->_hitPoints >= damage ? this->_hitPoints - damage : 0);

    std::cout       <<  "ClapTrap "     <<  this->_name     <<  " took "         <<  
                    damage              <<  " damage"       <<  " and now has "  <<
                    this->_hitPoints    <<  " hit points!"  <<  std::endl        ;

}

void    ClapTrap::beRepaired( unsigned int repairPoints )
{
    if (!this->_energyPoints)
    {
        std::cout   <<  "ClapTrap "  <<   this->_name  <<  " has no energy points left to repair itself!" << std::endl;
        return;
    }

    this->_energyPoints--;
    this->_hitPoints += repairPoints; 

    std::cout   <<  "ClapTrap "     <<  this->_name <<  " was successfully repaired with "  <<  
                repairPoints        << " repair points and now has "                         << 
                this->_hitPoints    <<  " hit points "                                      <<  
                std::endl                                                                   ; 

}