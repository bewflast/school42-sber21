#ifndef     DOG_HPP
# define    DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    Dog( const std::string );

public:
    Dog( void );
    ~Dog();
    Dog( const Dog& );
    Dog& operator=( const Dog& );

    const std::string&  getType()   const;
    void                makeSound() const;
};

#endif