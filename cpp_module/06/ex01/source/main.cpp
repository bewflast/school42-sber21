#include <stdint.h>
#include <iostream>

struct Data
{
    int _a;
    Data() : _a(10) {};
};

uintptr_t serialize( Data* ptr )
{
    return ( reinterpret_cast<uintptr_t>(ptr) );
};

Data*   deserialize( uintptr_t raw )
{
    return ( reinterpret_cast<Data*>(raw) );
};

int main()
{
    Data data;
    std::cout << serialize(&data) << " " << deserialize(serialize(&data)) << " " << &data;

    return (0);
}