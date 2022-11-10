#ifndef     ITER_HPP
# define    ITER_HPP

# include <stdint.h>
# include <iostream>

template<typename T>
void    println(T& item)
{
    std::cout   <<  item    <<  std::endl;
}

template<typename T>
void    iter(T* addr, size_t len, void(*functor)(T&))
{
    for(size_t i = 0; i < len; functor(addr[i++]));
}

#endif