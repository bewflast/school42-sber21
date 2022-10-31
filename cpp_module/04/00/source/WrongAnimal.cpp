#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( const std::string type)
:
    _type(type)
{};
WrongAnimal::WrongAnimal( void )
:
    _type("WrongAnimal")
{};
WrongAnimal::WrongAnimal( const WrongAnimal& other )
:
    _type(other._type)
{};

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
    this->_type = other._type;

    return (*this);
};
WrongAnimal::~WrongAnimal()
{
    std::cout   <<  "destructor called for WrongAnimal"    <<  std::endl;
}

void    WrongAnimal::makeSound( void )   const
{
    std::cout   <<  "meta sound of WrongAnimal???"   <<  std::endl;
}

const std::string&  WrongAnimal::getType( void ) const
{
    return (this->_type);
}