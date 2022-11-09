#include    <ctime>
#include    <cstdlib>
#include    <iostream>

struct  Base                {   virtual ~Base(){};  };
struct  A   :   public Base {   ~A(){};             };
struct  B   :   public Base {   ~B(){};             };
struct  C   :   public Base {   ~C(){};             };

Base* generate()
{
    std::srand(std::time(nullptr));
    std::cout   <<  "generated ";
    switch (1 + std::rand() % 3)
    {
    case 1:
        std::cout   <<  "A" <<  std::endl;
        return (new A);
    case 2:
        std::cout   <<  "B" <<  std::endl;
        return (new B);
    default:
        std::cout   <<  "C" <<  std::endl;
        return (new C);
    }
}

void identify(Base* ptr)
{
    if (dynamic_cast<A*>(ptr))
        std::cout   <<  "(ptr) A" <<  std::endl;
    if (dynamic_cast<B*>(ptr))
        std::cout   <<  "(ptr) B" <<  std::endl;
    if (dynamic_cast<C*>(ptr))
        std::cout   <<  "(ptr) C" <<  std::endl;
}

void identify(Base& ref)
    try
{
    (void)dynamic_cast<A&>(ref);
    std::cout   <<  "(ref) A" <<  std::endl;
}
    catch(const std::bad_cast& e)
{
    try 
    {
        (void)dynamic_cast<B&>(ref);
        std::cout   <<  "(ref) B" <<  std::endl;
    }
    catch (const std::bad_cast& e)
    {
        std::cout   <<  "(ref) C" <<  std::endl;
    }
}
    

int main()
{
    Base* kega = generate();

    identify(kega);
    identify(*kega);

    return (0);
}
