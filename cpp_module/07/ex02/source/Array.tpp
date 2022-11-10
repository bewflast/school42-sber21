#ifndef     ARRAY_TPP
# define    ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::~Array()
{
    delete[] this->_arr;
};

template<typename T>
Array<T>::Array()   :   _arr(new T[0]), _size(0) {};

template<typename T>
Array<T>::Array( const Array& other )   
:   
    _arr(new T[other.size()]), 
    _size(other.size())
{
    for(size_t i = 0; i < this->_size; ++i)
        this->_arr[i] = other[i];
}

template<typename T>
Array<T>& Array<T>::operator=( const Array& other )
{
    if (this->_size > 0)
        delete[] this->_arr;
    
    this->_arr  = new T[other.size()];
    this->_size = other.size();

    for(size_t i = 0; i < this->_size; ++i)
        this->_arr[i] = other[i];
}

template<typename T>
Array<T>::Array( const uint32_t size )
:
    _arr(new T[size]),
    _size(size)
{};

template<typename T>
size_t    Array<T>::size()          const
{
    return (this->_size);
};

template<typename T>
T& Array<T>::operator[]( const uint32_t ix )    const
{
    if (ix > this->_size - 1)
        throw(std::out_of_range("index of element is out of range of Array"));
    
    return (this->_arr[ix]);
}


#endif