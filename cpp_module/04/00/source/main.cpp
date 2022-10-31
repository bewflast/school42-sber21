#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal*   j       = new Dog();
    const Animal*   i       = new Cat();
    const Animal*   meta    = new Animal();

    std::cout   <<  j->getType()    <<  " " <<  std::endl;
    std::cout   <<  i->getType()    <<  " " <<  std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete j;
    delete i;
    delete meta;

    const WrongAnimal*  wcat    = new WrongCat();
    const WrongAnimal*  wmeta   = new WrongAnimal();

    std::cout   <<  wcat->getType()     <<  " " <<  std::endl;
    std::cout   <<  wmeta->getType()    <<  " " <<  std::endl;   

    wcat->makeSound();
    wmeta->makeSound();

    delete wcat;
    delete wmeta;

    return (0);
}