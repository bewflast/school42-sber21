#include "Character.hpp"
#include "AMateria.hpp"
#include "Ground.hpp"

extern Ground ground;

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (this->_materias[i])
            delete this->_materias[i];
    delete[] this->_materias;
}

Character::Character( void )
:
    _name("unknown"),
    _materias(new AMateria*[4])
{
    this->_materias[0] = nullptr;
    this->_materias[1] = nullptr;
    this->_materias[2] = nullptr;
    this->_materias[3] = nullptr;
};

Character::Character( const Character& other)
:
    _name(other._name),
    _materias(new AMateria*[4])
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = other._materias[i]->clone();
};

Character::Character( const std::string& name)
:
    _name(name),
    _materias(new AMateria*[4])
{
    this->_materias[0] = nullptr;
    this->_materias[1] = nullptr;
    this->_materias[2] = nullptr;
    this->_materias[3] = nullptr;
};

Character&   Character::operator=( const Character& other)
{
    this->_name = other._name;

    for(int i = 0; i < 4; i++)
    {
        if (this->_materias[i])
            delete _materias[i];
        this->_materias[i] = other._materias[i]->clone();
    }

    return (*this);
}

const std::string&  Character::getName()   const
{
    return (this->_name);
}

void                Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || !this->_materias[idx])
    {
        std::cout   <<  "BRUH smth is wrong with idx or materia"   << std::endl;
        return ;
    }
    this->_materias[idx]->use(target);
}

void                Character::equip(AMateria* m)
{
    size_t  ix = 0;
    for (ix = 0; ix < 4 && this->_materias[ix];ix++);
    if (ix == 3 && this->_materias[3])
    {
        std::cout   <<  "All slots of " << this->getName()  << " char are full" << std::endl;
        return ;
    }

    this->_materias[ix] = m;
    std::cout << ix << std::endl;
}

void            Character::unequip( int ix )
{
    if (ix < 0 || ix > 3 || !this->_materias[ix])
    {
        std::cout   <<  "Index is shit or material is null" << std::endl;
        return ;
    }

    ground.put(this->_materias[ix]);
    this->_materias[ix] = nullptr;
}
