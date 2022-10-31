#include "Cat.hpp"

Cat::Cat( const std::string type)
:
    AAnimal(type),
    _brain(new Brain())
{};
Cat::Cat( void )
:
    AAnimal(),
    _brain(new Brain())
{};
Cat::Cat( const Cat& other )
:
    AAnimal(other),
    _brain(new Brain(*(other._brain)))
{};

Cat& Cat::operator=( const Cat& other )
{
    this->_type         = other._type;
    *(this->_brain)     = *(other._brain);
    return (*this);
};
Cat::~Cat()
{
    delete this->_brain;
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