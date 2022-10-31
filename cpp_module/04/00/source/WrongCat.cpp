#include "WrongCat.hpp"

WrongCat::WrongCat( const std::string type)
:
    WrongAnimal(type)
{};
WrongCat::WrongCat( void )
:
    WrongAnimal()
{};
WrongCat::WrongCat( const WrongCat& other )
:
    WrongAnimal(other)
{};

WrongCat& WrongCat::operator=( const WrongCat& other )
{
    this->_type = other._type;

    return (*this);
};
WrongCat::~WrongCat()
{
    std::cout   <<  "destructor called for WrongCat"    <<  std::endl;
}

void    WrongCat::makeSound( void )   const
{
    std::cout   <<  "mmmmmmmmmeeeeeeeeeeeeeeeooooooowwwwwwwww"   <<  std::endl;
}

const std::string&  WrongCat::getType( void ) const
{
    return (this->_type);
}