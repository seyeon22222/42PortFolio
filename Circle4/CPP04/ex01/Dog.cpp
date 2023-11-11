#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->dogBrain = new Brain();
}

Dog::Dog(std::string type)
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = type;
}

Dog::~Dog(void)
{
    std::cout << "Dog destroyer called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = obj.getType();
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = obj.getType();
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog make sound 'Wal Wal'" << std::endl;
}