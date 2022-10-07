#include "Zombie.hpp"

void    randomChump( std::string name );
Zombie* newZombie( std::string name );

int main( void )
{
    Zombie* zptr;

    std::string fname("");
    std::string sname("");

    std::cin >> fname >> sname;

    zptr = newZombie(fname);
    randomChump(sname);

    zptr->announce();
    zptr->announce();
    zptr->announce();
    zptr->announce();
    zptr->announce();
    
    delete zptr;

    return (0);
}