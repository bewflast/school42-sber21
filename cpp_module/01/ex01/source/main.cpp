#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

void annnounceHorde( int hSize )
{
    Zombie* horde = zombieHorde(hSize, "bruh");

    for (int i = 0; i < hSize; horde[i++].announce());
    
    delete[] horde;
}

int main( void )
{
    annnounceHorde(10);
    return (0);
}