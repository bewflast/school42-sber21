#ifndef     EASYFIND_HPP
# define    EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container,  int x)
{
    typename T::iterator res = find(container.begin(), container.end(), x);
    if (*res != x)
        throw(std::exception());

    return (res);
};



#endif