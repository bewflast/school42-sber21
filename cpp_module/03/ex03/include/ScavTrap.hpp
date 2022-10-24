#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    ScavTrap( void );

public:
   ~ScavTrap();
    ScavTrap( std::string );
    ScavTrap( const ScavTrap& ); 
    ScavTrap& operator=( const ScavTrap& );

    void    attack( const std::string& );
    void    guardGate( void ) const;
};

#endif