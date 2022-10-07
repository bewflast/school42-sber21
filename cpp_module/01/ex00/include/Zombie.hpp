#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    Zombie();
    std::string name;

public:
    
    Zombie( std::string name )
    :
        name(name)
    {};

    void    announce( void );

    void                setName( std::string newName );
    const std::string&  getName( void ) const;

    ~Zombie();
};

#endif