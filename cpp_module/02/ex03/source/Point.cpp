#include "Point.hpp"

Point::Point( void )
:
    _x(0),
    _y(0)
{};

Point::~Point()
{};

Point::Point(const float x, const float y)
:
    _x(x),
    _y(y)
{}

Point::Point( const Point& other )
:
    _x(other._x),
    _y(other._y)
{};

Point&  Point::operator=(const Point& other)
{
    const_cast<Fixed&>(this->_x) = Fixed(other._x);
    const_cast<Fixed&>(this->_y) = Fixed(other._y);

    return (*this);
}

float  Point::getX( void ) const
{
    return (this->_x.toFloat());
}

float  Point::getY( void ) const
{
    return (this->_y.toFloat());
}