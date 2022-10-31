#ifndef     AANIMAL_HPP
# define    AANIMAL_HPP

# include <iostream>

class AAnimal
{

protected:
    AAnimal( const std::string );    
    std::string _type;
    
public:
    AAnimal( void );
    virtual ~AAnimal() = 0;
    AAnimal( const AAnimal& );
    AAnimal& operator=( const AAnimal& );

    virtual const std::string&  getType()   const   = 0;
    virtual void                makeSound() const   = 0;
};

#endif