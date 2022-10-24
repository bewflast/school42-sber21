#include "FragTrap.hpp"

int main()
{
 	std::cout << "=============" << std::endl;
	FragTrap empty("emt");
	empty = FragTrap("NotEmpty");
	empty.attack("KEKUS");
	std::cout << "=============" << std::endl;
	std::cout << "=============" << std::endl;
	FragTrap fragtrap("Frag");
	fragtrap.attack("Mikky");
	fragtrap.highFivesGuys();
	std::cout << "=============" << std::endl;
	fragtrap.takeDamage(1);
	fragtrap.takeDamage(99);
	fragtrap.beRepaired(100);
	std::cout << "=============" << std::endl;
	FragTrap copy(fragtrap);
	copy.attack("another Copy");
	std::cout << "=============" << std::endl;
    
	return (0);
}