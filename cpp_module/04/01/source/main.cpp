#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
int main()
{
    /*Dog* f = new Dog();
    f->_brain->setIdea(3, "maka");
    Dog* s = new Dog(*f); 
    std::cout << f->_brain->getIdea(3) << "   " << s->_brain->getIdea(3) << std::endl;
    f->_brain->setIdea(3, "baka");
    std::cout << f->_brain->getIdea(3) << "   " << s->_brain->getIdea(3) << std::endl;

    delete f;
    delete s;
    */

    Animal**  animals = new Animal*[10];
    for(int i = 0; i < 10; i++)
        if (i <= 4)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    
    dynamic_cast<Cat*>(animals[6])->_brain->setIdea(5, "smakish");
    std::cout << dynamic_cast<Cat*>(animals[6])->_brain->getIdea(5) << std::endl;

    std::cout << dynamic_cast<Cat*>(animals[7])->_brain->getIdea(5) << std::endl;
    dynamic_cast<Cat&>(*animals[7]) = dynamic_cast<Cat&>(*animals[6]);
    std::cout << dynamic_cast<Cat*>(animals[7])->_brain->getIdea(5) << std::endl;

    dynamic_cast<Cat*>(animals[6])->_brain->setIdea(5, "BRUH");
    std::cout << dynamic_cast<Cat*>(animals[6])->_brain->getIdea(5) << std::endl;
    std::cout << dynamic_cast<Cat*>(animals[7])->_brain->getIdea(5) << std::endl;

    for(int i = 0; i < 10; delete animals[i++]);
    delete[] animals;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    return (0);
}