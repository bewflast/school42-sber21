#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
class Fixed
{
    int                 _value;
    static const int    _fbits;

public:
    Fixed();
    ~Fixed();
    Fixed( const Fixed& );
    Fixed( const int );
    Fixed( const float );
    Fixed&  operator=( const Fixed& );

    int     getRawBits( void ) const;
    void    setRawBits( const int );

    int     toInt( void )   const;
    float   toFloat( void ) const;

    friend  std::ostream& operator<<(std::ostream&, const Fixed&);

    bool    operator>(const Fixed&)     const;
    bool    operator<(const Fixed&)     const;
    bool    operator>=(const Fixed&)    const;
    bool    operator<=(const Fixed&)    const;
    bool    operator==(const Fixed&)    const;
    bool    operator!=(const Fixed&)    const;

    Fixed  operator+(const Fixed&)     const;
    Fixed  operator-(const Fixed&)     const;
    Fixed  operator*(const Fixed&)     const;
    Fixed  operator/(const Fixed&)     const;

    Fixed&  operator++();
    Fixed&  operator--();
    Fixed   operator++(int);
    Fixed   operator--(int);

    static Fixed&       min(Fixed&, Fixed&);
    static Fixed&       max(Fixed&, Fixed&);
    static const Fixed& min(const Fixed&, const Fixed&);
    static const Fixed& max(const Fixed&, const Fixed&);


};

#endif