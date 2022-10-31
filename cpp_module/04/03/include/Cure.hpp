#ifndef     CURE_HPP
# define    CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    ~Cure();
    Cure( void );
    Cure( const Cure& );
    Cure( const std::string& );
    Cure&   operator=( const Cure& );

    Cure*       clone() const;
    void        use( ICharacter& );

};

#endif