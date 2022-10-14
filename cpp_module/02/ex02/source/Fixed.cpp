#include "Fixed.hpp"

const int Fixed::_fbits   =   8;

Fixed::Fixed()  : _value(0)  
{
    //   <<  "Default constructor called"    <<  std::endl;
}

Fixed::~Fixed()
{
    //   <<  "Destructor called"    <<  std::endl;
}

Fixed::Fixed( const Fixed& other )  :   _value(other._value)
{
    //   <<  "Copy constructor called"   <<  std::endl;
}

Fixed::Fixed( const int val ) : _value(val * (1 << Fixed::_fbits))
{
    //   <<  "Conversion constructor called (->int)" <<  std::endl;

}

Fixed::Fixed( const float val ) : _value(static_cast<int>(roundf(val * (1 << Fixed::_fbits))))
{
     //   <<  "Conversion constructor called (->float)" <<  std::endl;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    this->_value = other._value;
    //   <<  "Copy assignment operator called"   <<  std::endl;
    return (*this);
}

int Fixed::getRawBits() const
{
    //   <<  "getRawBits member function called" <<  std::endl;
    return (this->_value);
}

void    Fixed::setRawBits( const int raw )
{
    //   <<  "setRawBits member function called" <<  std::endl;
    this->_value = raw;
}

int Fixed::toInt() const
{
    return (this->_value >> Fixed::_fbits);
}

float   Fixed::toFloat() const
{
    return (static_cast<float>(this->_value) / static_cast<float>(1 << Fixed::_fbits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();

    return (out);
}


bool    Fixed::operator>(const Fixed& other)    const
{
    return (this->getRawBits() > other.getRawBits());
}
bool    Fixed::operator<(const Fixed& other)    const
{
    return (this->getRawBits() < other.getRawBits());
}
bool    Fixed::operator>=(const Fixed& other)    const
{
    return (this->getRawBits() >= other.getRawBits());
}
bool    Fixed::operator<=(const Fixed& other)    const
{
    return (this->getRawBits() <= other.getRawBits());
}
bool    Fixed::operator==(const Fixed& other)    const
{
    return (this->getRawBits() == other.getRawBits());
}
bool    Fixed::operator!=(const Fixed& other)    const
{
    return (this->getRawBits() != other.getRawBits());
}


Fixed  Fixed::operator+(const Fixed& other)     const
{
    Fixed result(*this);
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return ( result );
}
Fixed  Fixed::operator-(const Fixed& other)     const
{
    Fixed result(*this);
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return ( result );
}
Fixed  Fixed::operator*(const Fixed& other)     const
{
    Fixed   result(*this);
    result.setRawBits((this->getRawBits() * other.getRawBits()) / (1 << Fixed::_fbits));
    return ( result );
}
Fixed  Fixed::operator/(const Fixed& other)     const
{
    Fixed   result(*this);
    result.setRawBits((this->getRawBits() * (1 << Fixed::_fbits)) / other.getRawBits() );
    return ( result );
}


Fixed&  Fixed::operator++()
{
    ++(this->_value);
    return (*this);
}
Fixed&  Fixed::operator--()
{
    --(this->_value);
    return (*this);
}
Fixed  Fixed::operator++(int)
{
    Fixed   old_value(*this);
    ++(this->_value);
    return (old_value);
}
Fixed  Fixed::operator--(int)
{
    Fixed   old_value(*this);
    --(this->_value);
    return (old_value);
}


Fixed&  Fixed::min(Fixed& x, Fixed& y)
{
    return (x < y ? x : y);
}
Fixed&  Fixed::max(Fixed& x, Fixed& y)
{
    return (x > y ? x : y);
}
const Fixed&  Fixed::min(const Fixed& x, const Fixed& y)
{
    return (x < y ? x : y);
}
const Fixed&  Fixed::max(const Fixed& x, const Fixed& y)
{
    return (x > y ? x : y);
}