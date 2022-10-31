#include "Cure.hpp"

Cure::~Cure()                                                       {};
Cure::Cure()                            : AMateria("cure")          {};
Cure::Cure( const Cure& other )         : AMateria(other._type)     {}
Cure::Cure( const std::string& type )   : AMateria(type)            {};
Cure&   Cure::operator=( const Cure& other )
{
    this->_type = other._type;

    return (*this);
}

Cure*   Cure::clone() const
{
    return(new Cure(*this));
}

void        Cure::use( ICharacter& target)
{
    std::cout   <<  "* heals "  << target.getName() <<  "\'s wounds *"  <<  std::endl;
}