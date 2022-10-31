#ifndef     BRAIN_HPP
# define    BRAIN_HPP

# include <string>
# include <sstream>

class Brain
{
    std::string* _ideas;

public:
    ~Brain();
    Brain( void );
    Brain( const Brain& );
    Brain( const std::string* );
    Brain&  operator=( const Brain& );

    const std::string&  getIdea( int )  const;
    void                setIdea( int, std::string );
};

#endif