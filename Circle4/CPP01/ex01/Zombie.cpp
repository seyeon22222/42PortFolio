#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << "<" << this->name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set(std::string name)
{
    this->name = name;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "<" << this->name << ">" << "create...." << std::endl;
}

Zombie::Zombie(void)
{
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "<" << this->name << ">" << "die...." << std::endl;
}