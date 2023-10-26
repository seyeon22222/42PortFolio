#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << "<" << this->name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "<" << this->name << ">" << "create...." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "<" << this->name << ">" << "die...." << std::endl;
}