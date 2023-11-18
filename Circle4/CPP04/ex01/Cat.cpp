#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->catBrain = new Brain();
}

Cat::Cat(std::string type)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = type;
	this->catBrain = new Brain();
}

Cat::~Cat(void)
{
	delete this->catBrain;
    std::cout << "Cat destoryer called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
	*this = obj;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this == &obj)
		return (*this);
    std::cout << "Cat assinment constructor called" << std::endl;
    this->type = obj.getType();
	this->catBrain = obj.catBrain;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat make sound 'meow'" << std::endl;
}