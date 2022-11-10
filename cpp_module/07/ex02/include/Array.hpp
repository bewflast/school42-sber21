#ifndef     ARRAY_HPP
# define    ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
    T*      _arr;
    size_t  _size;

public:
    ~Array();
    Array();
    Array( const uint32_t size );
    Array( const Array& other);
    Array&  operator=( const Array& other );

    T&  operator[]( const uint32_t ix )   const;

    size_t    size()          const;

};

#endif