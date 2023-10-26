#include "Zombie.hpp"

int main(void)
{
    Zombie *temp; // heap
    Zombie  temp2("member"); //stack

    temp = newZombie("kardet");
    randomChump("member2");

    temp->announce();
    temp2.announce();
    delete temp;
    return (0);
}