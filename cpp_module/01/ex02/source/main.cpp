#include <iostream>

int main ( void )
{
    std::string     str("HI THIS IS BRAIN");

    std::string*    str_p = &str;
    std::string&    str_r = str;

    std::cout   <<  "&str:\t"        <<  &str       <<  std::endl   <<  
                    "str_p:\t"       <<  str_p      <<  std::endl   <<
                    "&str_r:\t"      <<  &str_r     <<  std::endl   ;
    
    str = "HELLO THIS IS BRAIN";

    std::cout   <<  "\nAfter modifying str"         <<  std::endl   ;
    std::cout   <<  "str:\t"        <<  str         <<  std::endl   <<  
                    "*str_p:\t"     <<  *str_p      <<  std::endl   <<
                    "str_r:\t"      <<  str_r       <<  std::endl   ;
    
    *str_p = "BYE THIS IS BRAIN";

    std::cout   <<  "\nAfter modifying str_p"       <<  std::endl   ;
    std::cout   <<  "str:\t"        <<  str         <<  std::endl   <<  
                    "*str_p:\t"     <<  *str_p      <<  std::endl   <<
                    "str_r:\t"      <<  str_r       <<  std::endl   ;

    str_r = "bye...";

    std::cout   <<  "\nAfter modifying str_r"        <<  std::endl   ;
    std::cout   <<  "str:\t"        <<  str         <<  std::endl   <<  
                    "*str_p:\t"     <<  *str_p      <<  std::endl   <<
                    "str_r:\t"      <<  str_r       <<  std::endl   ;
    
    return(0);
}