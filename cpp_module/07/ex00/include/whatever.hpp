#ifndef     WHATEVER_HPP
# define    WHATEVER_HPP

template<typename T>
void    swap( T& first, T& second )
{
    T  temp;

    temp    = first; 
    first   = second;
    second  = temp;
}

template<typename T>
const T&   min( const T& x, const T& y )
{
    return (x < y ? x : y);
}

template<typename T>
const T&   max( const T& x, const T& y )
{
    return (x < y ? y : x);
}

#endif