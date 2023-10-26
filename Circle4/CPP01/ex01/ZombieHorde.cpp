#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *temp = new Zombie[N];
    std::string a;

    for (int i = 0; i< N; i++)
    {
        temp[i].set(name);
        temp[i].announce();
    }
    for (int i = 0; i< N; i++)
    {
        getline(std::cin, a);
        temp[i].set(name + a);
    }
    return (temp);
}
