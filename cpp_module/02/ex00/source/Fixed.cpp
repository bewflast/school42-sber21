#include "Fixed.hpp"

const int Fixed::_fbits   =   8;

Fixed::Fixed()  : _value(0)  
{
    std::cout   <<  "Default constructor called"    <<  std::endl;
}

Fixed::~Fixed()
{
    std::cout   <<  "Destructor called"    <<  std::endl;
}

Fixed::Fixed( const Fixed& other ) : _value(other._value)
{
    std::cout   <<  "Copy constructor called"   <<  std::endl;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    this->_value = other._value;
    std::cout   <<  "Copy assignment operator called"   <<  std::endl;
    return (*this);
}

int Fixed::getRawBits() const
{
    std::cout   <<  "getRawBits member function called" <<  std::endl;
    return (this->_value);
}

void    Fixed::setRawBits( const int raw )
{
    std::cout   <<  "setRawBits member function called" <<  std::endl;
    this->_value = raw;
}