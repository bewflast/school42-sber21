#include "Brain.hpp"

Brain::~Brain()
{
    delete[] this->_ideas;
};

Brain::Brain( void )
:
    _ideas(new std::string[100])
{
    std::ostringstream   tmp;
    for(int i = 0; i < 100; i++)
    {
        tmp.str("");
        tmp << "idea " << i;
        this->setIdea(i, tmp.str());
    }
};

Brain::Brain( const Brain& other )
:
    _ideas(new std::string[100])
{
    for(int i = 0; i < 100; i++)
        this->setIdea(i, other.getIdea(i));
};

Brain::Brain( const std::string* ideas )
:
    _ideas(new std::string[100])
{
    for(int i = 0; i < 100; i++)
        this->setIdea(i, ideas[i]); 
}

Brain&  Brain::operator=( const Brain& other )
{
    for(int i = 0; i < 100; i++)
        this->setIdea(i, other.getIdea(i));

    return (*this);
}

void    Brain::setIdea( int idx, std::string idea )
{
    this->_ideas[(idx <= 99 && 0 <= idx ? idx : 99)] = idea;
}

const std::string&  Brain::getIdea( int idx ) const
{
    return (this->_ideas[(idx <= 99 && 0 <= idx ? idx : 99)]);
}