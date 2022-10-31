#ifndef     WRONGANIMAL_HPP
# define    WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
    WrongAnimal( const std::string );
    std::string _type;

public:
    WrongAnimal( void );
    ~WrongAnimal();
    WrongAnimal( const WrongAnimal& );
    WrongAnimal& operator=( const WrongAnimal& );

    const std::string&  getType()   const;
    void                makeSound() const;
};

#endif