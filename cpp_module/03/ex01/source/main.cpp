#include "ScavTrap.hpp"

int main()
{
 	std::cout << "=============" << std::endl;
	ScavTrap empty("emt");
	empty = ScavTrap("LOL");
	empty.attack("KEKUS");
	std::cout << "=============" << std::endl;
	ScavTrap copy(empty);
	copy.attack("another copy");
	std::cout << "=============" << std::endl;
	ScavTrap scavTrap("SCAV");
	scavTrap.attack("Mikky");
	scavTrap.guardGate();
	std::cout << "=============" << std::endl;
	scavTrap.takeDamage(1);
	scavTrap.takeDamage(99);
	scavTrap.beRepaired(100);
    
	return 0;
}