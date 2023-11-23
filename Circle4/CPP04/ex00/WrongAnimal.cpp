#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = obj.getType();
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this == &obj)
		return (*this);
    std::cout << "WrongAnimal assingment constructor called" << std::endl;
    this->type = obj.getType();
    return (*this);
}

void    WrongAnimal::setType(std::string type)
{
    this->type = type;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal don't make sound" << std::endl;
}