#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    const Fixed _x;
    const Fixed _y;

public:
    Point( void );
    ~Point();
    Point( const Point& );
    Point( const float, const float );

    Point&  operator=(const Point&);

    float  getX( void ) const;
    float  getY( void ) const;

};

#endif