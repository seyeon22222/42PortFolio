#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destoryer called" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = type;
}

WrongCat::WrongCat(const WrongCat &obj)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = obj.getType();
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat assingment constructor called" << std::endl;
    this->type = obj.getType();
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat make sound 'meowwwwww'" << std::endl;
}