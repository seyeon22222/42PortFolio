#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = obj.getType();
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this == &obj)
		return (*this);
    std::cout << "Cat assinment constructor called" << std::endl;
    this->type = obj.getType();
    return (*this);
}

Cat::Cat(std::string type)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = type;
}

void Cat::makeSound(void) const
{
    std::cout << "Cat make sound 'meow'" << std::endl;
}