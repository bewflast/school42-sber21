#ifndef     ANIMAL_HPP
# define    ANIMAL_HPP

# include <iostream>

class Animal
{

protected:
    Animal( const std::string );    
    std::string _type;
    
public:
    Animal( void );
    virtual ~Animal();
    Animal( const Animal& );
    Animal& operator=( const Animal& );

    virtual const std::string&  getType()   const;
    virtual void                makeSound() const;
};

#endif