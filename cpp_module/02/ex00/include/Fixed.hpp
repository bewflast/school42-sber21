#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    int                 _value;
    static const int    _fbits;

public:
    Fixed();
    Fixed( const Fixed& );
    Fixed&  operator=( const Fixed& );
    ~Fixed();

    int getRawBits( void ) const;
    void    setRawBits( const int );

};

#endif