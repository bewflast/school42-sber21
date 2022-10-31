#include "Cat.hpp"

Cat::Cat( const std::string type)
:
    Animal(type)
{};
Cat::Cat( void )
:
    Animal()
{};
Cat::Cat( const Cat& other )
:
    Animal(other)
{};

Cat& Cat::operator=( const Cat& other )
{
    this->_type = other._type;

    return (*this);
};
Cat::~Cat()
{
    std::cout   <<  "virtual destructor called for Cat"    <<  std::endl;
}

void    Cat::makeSound( void )   const
{
    std::cout   <<  "mmmmmmmmmeeeeeeeeeeeeeeeooooooowwwwwwwww"   <<  std::endl;
}

const std::string&  Cat::getType( void ) const
{
    return (this->_type);
}