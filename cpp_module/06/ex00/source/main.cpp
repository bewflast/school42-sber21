#include <cstdlib>
#include <climits>
#include <iostream>
#include "Converter.hpp"

int error(const std::string& s)
{
	std::cout << "\033[1;31m" << s << "\033[0m" << std::endl;
	return 0;
}

int main(int ac, char **av)
{
	(void)ac;
	if (ac != 2)
		return (::error("Error count params"));
	Converter converter(av[1]);
	converter.Convert();
}