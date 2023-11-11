#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal constructor called" << std::endl;
    this->type = "Animal";
}

Animal::~Animal(void)
{
    std::cout << "Animal destoryer called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = obj.getType();
}

Animal &Animal::operator=(const Animal &obj)
{
    std::cout << "Animal assinment constructor called" << std::endl;
    this->type = obj.getType();
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void    Animal::setType(std::string type)
{
    this->type = type;
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal don't make sound" << std::endl;
}