#ifndef     DOG_HPP
# define    DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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