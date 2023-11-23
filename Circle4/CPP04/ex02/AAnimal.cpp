#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal constructor called" << std::endl;
    this->type = "AAnimal";
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    this->type = obj.getType();
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
	if (this == &obj)
		return (*this);
    std::cout << "AAnimal assinment constructor called" << std::endl;
    this->type = obj.getType();
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}

void    AAnimal::setType(std::string type)
{
    this->type = type;
}

void    AAnimal::makeSound(void) const
{
    std::cout << "AAnimal don't make sound" << std::endl;
}