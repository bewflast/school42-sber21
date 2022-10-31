#include "Ground.hpp"

Ground::~Ground()
{    for (size_t i = 0; i < this->getItemsCount(); i++)
        delete this->_items[i];
    delete[] this->_items;
}

Ground::Ground()
:
    _items(new AMateria*[1])
{
    this->_items[0] = nullptr;
}

size_t  Ground::getItemsCount() const
{
    size_t  size;
    for (size = 0; this->_items[size]; size++);

    return (size);
};

void    Ground::put( AMateria* item )
{
    size_t  _items_count = this->getItemsCount();

    AMateria** tmp = new AMateria*[_items_count + 2];

    for (size_t i = 0; i < _items_count; i++)
        tmp[i] = this->_items[i];
    
    tmp[_items_count]     = item;
    tmp[_items_count + 1] = nullptr;

    delete[] this->_items;

    this->_items = tmp;
}
