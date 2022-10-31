#include "Dog.hpp"

Dog::Dog( const std::string type)
:
    Animal(type)
{};
Dog::Dog( void )
:
    Animal()
{};
Dog::Dog( const Dog& other )
:
    Animal(other)
{};

Dog& Dog::operator=( const Dog& other )
{
    this->_type = other._type;

    return (*this);
};
Dog::~Dog()
{
    std::cout   <<  "virtual destructor called for Dog"    <<  std::endl;
}

void    Dog::makeSound( void )   const
{
    std::cout   <<  "*bark bark bark*"   <<  std::endl;
}

const std::string&  Dog::getType( void ) const
{
    return (this->_type);
}