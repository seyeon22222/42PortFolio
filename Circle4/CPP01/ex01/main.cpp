#include "Zombie.hpp"

int main(void)
{
    Zombie  *temp;
    int     N = 5;

    temp = zombieHorde(N, "hello");
    for (int i = 0; i < N; i++)
        temp[i].announce();
    delete[]     temp;
    return (0);
}