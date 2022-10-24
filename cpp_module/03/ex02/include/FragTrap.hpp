#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    FragTrap( void );

public:
   ~FragTrap();
    FragTrap( std::string );
    FragTrap( const FragTrap& );

    FragTrap& operator=( const FragTrap& );

    void    attack( const std::string& );
    void    highFivesGuys( void ) const;
};

#endif