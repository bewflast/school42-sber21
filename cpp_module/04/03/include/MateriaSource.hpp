#ifndef     MATERIASOURCE_HPP
# define    MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    AMateria**  _knownMaterias;
    

public:
    ~MateriaSource();
    MateriaSource( void );
    MateriaSource( const MateriaSource& );
    MateriaSource&   operator=( const MateriaSource& );
    
    size_t  getKnownMateriasCount() const;
    void learnMateria( AMateria* );
    AMateria* createMateria( std::string const& );
};

#endif