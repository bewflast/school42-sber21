#include "Dog.hpp"

Dog::Dog( const std::string type)
:
    AAnimal(type),
    _brain(new Brain())
{};
Dog::Dog( void )
:
    AAnimal(),
    _brain(new Brain())
{};
Dog::Dog( const Dog& other )
:
    AAnimal(other),
    _brain(new Brain(*(other._brain)))
{};

Dog& Dog::operator=( const Dog& other )
{
    this->_type         = other._type;
    *(this->_brain)     = *(other._brain);

    return (*this);
};
Dog::~Dog()
{
    delete this->_brain;
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