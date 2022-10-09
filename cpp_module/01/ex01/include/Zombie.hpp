#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    std::string name;

public:
    
    Zombie( std::string name )
    :
        name(name)
    {};
    
    Zombie()
    :
        name("")
    {};

    void    announce( void );

    void                setName( std::string newName );
    const std::string&  getName( void ) const;

    ~Zombie();
};

#endif