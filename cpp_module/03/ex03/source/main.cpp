#include "DiamondTrap.hpp"

int main()
{
	
	std::cout << "=============" << std::endl;
	DiamondTrap empty("et");
	std::cout << "=============" << std::endl;
	DiamondTrap diamond("DIAMOND");
	std::cout << "=============" << std::endl;
	diamond.attack("EMERALD");
	std::cout << "=============" << std::endl;
	return (0);

}