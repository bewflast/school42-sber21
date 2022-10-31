#include "MateriaSource.hpp"

size_t MateriaSource::getKnownMateriasCount( ) const
{
    size_t  size;
    for (size = 0; this->_knownMaterias[size]; size++);

    return (size);
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < this->getKnownMateriasCount(); i++)
        delete this->_knownMaterias[i];
    delete[] this->_knownMaterias;
}

MateriaSource::MateriaSource( void )
:
    _knownMaterias(new AMateria*[1])
{
    _knownMaterias[0] = nullptr;
};

MateriaSource::MateriaSource( const MateriaSource& other)
:
    _knownMaterias(new AMateria*[other.getKnownMateriasCount()])
{
    for (size_t i = 0; i < other.getKnownMateriasCount(); i++);
};

void MateriaSource::learnMateria( AMateria* materia)
{
    if (!materia || materia->getType() == "(NULL)")
        return;
    
    int mats_count = this->getKnownMateriasCount();
    for (int i = 0; i < mats_count; i++)
        if (this->_knownMaterias[i] && (materia->getType() == this->_knownMaterias[i]->getType()))
            return;

    AMateria** tmp = new AMateria*[mats_count + 2];
    for (int i = 0; i < mats_count; i++)
        tmp[i] = this->_knownMaterias[i]->clone();

    tmp[mats_count]     = materia->clone();
    tmp[mats_count + 1] = nullptr;

    for (int i = 0; i < mats_count; i++)
        delete this->_knownMaterias[i];
    delete[] this->_knownMaterias;

    this->_knownMaterias = tmp;

    delete materia;
}

AMateria* MateriaSource::createMateria( std::string const& type)
{
    size_t ix = 0;
    for (ix = 0; ix < this->getKnownMateriasCount(); ix++)
        if (this->_knownMaterias[ix]->getType() == type)
            return (this->_knownMaterias[ix]->clone());
    
    return (nullptr);
}