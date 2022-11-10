#include "easyfind.hpp"

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> a(10, 5);
    std::cout << *easyfind(a, 5);

    return (0);
}