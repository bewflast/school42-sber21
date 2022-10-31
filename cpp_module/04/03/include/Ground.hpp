#ifndef     GROUND_HPP
# define    GROUND_HPP

# include "AMateria.hpp"

class Ground
{
    AMateria**  _items;
    //size_t  getItemsCount() const;

public:
    ~Ground();
    Ground( void );
    size_t  getItemsCount() const;
    void        put(AMateria* item);
};

#endif