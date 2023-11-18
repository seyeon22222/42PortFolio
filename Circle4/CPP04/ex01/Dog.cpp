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
	this->dogBrain = new Brain();
    this->type = type;
}

Dog::~Dog(void)
{
	delete dogBrain;
    std::cout << "Dog destroyer called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
	*this = obj;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	if (this == &obj)
		return (*this);
    std::cout << "Dog constructor called" << std::endl;
    this->type = obj.getType();
	this->dogBrain = obj.dogBrain;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog make sound 'Wal Wal'" << std::endl;
}