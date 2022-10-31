#ifndef     CHARACTER_HPP
# define    CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter
{

    std::string _name;
    AMateria**  _materias;

public:

    ~Character();
    Character( void );
    Character( const Character& );
    Character( const std::string& );
    Character&   operator=( const Character& );

    const std::string&  getName()   const;
    void                unequip(int idx);
    void                equip(AMateria* m);
    void                use(int idx, ICharacter& target);

};

#endif