#include "AAnimal.hpp"

AAnimal::AAnimal( const std::string type)
:
    _type(type)
{};
AAnimal::AAnimal( void )
:
    _type("AAnimal")
{};
AAnimal::AAnimal( const AAnimal& other )
:
    _type(other._type)
{};

AAnimal& AAnimal::operator=( const AAnimal& other )
{
    this->_type = other._type;

    return (*this);
};
AAnimal::~AAnimal()
{
    std::cout   <<  "virtual destructor called for AAnimal"    <<  std::endl;
}

void    AAnimal::makeSound( void )   const
{
    std::cout   <<  "meta sound of AAnimal???"   <<  std::endl;
}

const std::string&  AAnimal::getType( void ) const
{
    return (this->_type);
}