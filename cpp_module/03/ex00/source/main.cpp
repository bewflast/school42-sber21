#include "ClapTrap.hpp"

int main()
{
    ClapTrap    f   =   std::string("first");
    ClapTrap    s("second");
    ClapTrap    f_c(f);
    ClapTrap    s_c(s);
    ClapTrap    f_cc("n");
    ClapTrap    s_cc("m");

    f_cc = f;
    s_cc = s;

    for (int i = 0; i < 20; i++)
    {
        f.attack("f target");
        s.attack("s target");
        f_c.attack("f_c target");
        s_c.attack("s_c target");
        f_cc.attack("f_cc target");
        s_cc.attack("s_cc target");
    }
    

    
	return 0;
}