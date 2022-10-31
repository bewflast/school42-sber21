#include "AMateria.hpp"

AMateria::~AMateria()                                                   {};
AMateria::AMateria()                            : _type("(NULL)")       {};
AMateria::AMateria( const AMateria& other )     : _type(other._type)    {}
AMateria::AMateria( const std::string& type )   : _type(type)           {};
AMateria&   AMateria::operator=( const AMateria& other )
{
    this->_type = other._type;

    return (*this);
}

const std::string&  AMateria::getType() const
{
    return (this->_type);
}

void        AMateria::use( ICharacter& character)
{
    std::cout   <<  "WTF cannot use materia on " << character.getName() << " cos materia is wrong!!!!" <<  std::endl; 
}