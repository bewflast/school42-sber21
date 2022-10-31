#ifndef     ICE_HPP
# define    ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    ~Ice();
    Ice( void );
    Ice( const Ice& );
    Ice( const std::string& );
    Ice&   operator=( const Ice& );

    Ice*        clone() const;
    void        use( ICharacter& );

};

#endif