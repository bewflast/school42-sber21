#include "Ice.hpp"

Ice::~Ice()                                                         {};
Ice::Ice()                              : AMateria("ice")           {};
Ice::Ice( const Ice& other )            : AMateria(other._type)     {}
Ice::Ice( const std::string& type )     : AMateria(type)            {};
Ice&   Ice::operator=( const Ice& other )
{
    this->_type = other._type;

    return (*this);
}

Ice*   Ice::clone() const
{
    return(new Ice(*this));
}

void        Ice::use( ICharacter& target)
{
    std::cout   <<  "* shoots an ice bolt at "  << target.getName() << std::endl;
}