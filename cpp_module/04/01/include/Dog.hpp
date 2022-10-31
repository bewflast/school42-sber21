#ifndef     DOG_HPP
# define    DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    Dog( const std::string );
public:
    Brain*  _brain;
    
    Dog( void );
    ~Dog();
    Dog( const Dog& );
    Dog& operator=( const Dog& );

    const std::string&  getType()   const;
    void                makeSound() const;
};

#endif