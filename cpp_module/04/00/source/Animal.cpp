#include "Animal.hpp"

Animal::Animal( const std::string type)
:
    _type(type)
{};
Animal::Animal( void )
:
    _type("Animal")
{};
Animal::Animal( const Animal& other )
:
    _type(other._type)
{};

Animal& Animal::operator=( const Animal& other )
{
    this->_type = other._type;

    return (*this);
};
Animal::~Animal()
{
    std::cout   <<  "virtual destructor called for Animal"    <<  std::endl;
}

void    Animal::makeSound( void )   const
{
    std::cout   <<  "meta sound of Animal???"   <<  std::endl;
}

const std::string&  Animal::getType( void ) const
{
    return (this->_type);
}