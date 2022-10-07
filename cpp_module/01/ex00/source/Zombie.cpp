#include "Zombie.hpp"

const std::string& Zombie::getName() const
{
    return (this->name);
}

void    Zombie::setName( std::string newName )
{
    this->name = newName;
}

void    Zombie::announce ()
{
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "ZzzzZZombiee " << this->getName() << " has..died?" << std::endl;
}