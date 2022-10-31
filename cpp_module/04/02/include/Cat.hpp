#ifndef     CAT_HPP
# define    CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    Cat( const std::string );

public:
    Brain*  _brain;

    Cat( void );
    ~Cat();
    Cat( const Cat& );
    Cat& operator=( const Cat& );

    const std::string&  getType()   const;
    void                makeSound() const;
};

#endif