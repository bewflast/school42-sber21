#ifndef     AMATERIA_HPP
# define    AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"
class ICharacter;
class AMateria
{
protected:
    std::string _type;

public:
    virtual ~AMateria();
    AMateria( void );
    AMateria( const AMateria& );
    AMateria( const std::string& );
    AMateria&   operator=( const AMateria& );

    virtual AMateria*           clone()             const = 0;
    virtual const std::string&  getType()           const;
    virtual void                use( ICharacter& );
};

#endif