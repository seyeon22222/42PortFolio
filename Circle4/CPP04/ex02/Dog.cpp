#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->dogBrain = new Brain();
	this->dogBrain->fillBrain("Dog");
}

Dog::Dog(std::string type)
{
    std::cout << "Dog constructor called" << std::endl;
	this->dogBrain = new Brain();
	this->dogBrain->fillBrain("Dog");
    this->type = type;
}

Dog::~Dog(void)
{
	delete dogBrain;
    std::cout << "Dog destructor called" << std::endl;
}


Dog::Dog(const Dog &obj)
{
	*this = obj;
    std::cout << "Dog copy constructor called" << std::endl;
}

// shallow copy
// Dog &Dog::operator=(const Dog &obj)
// {
// 	if (this == &obj)
// 		return (*this);
//     std::cout << "Dog constructor called" << std::endl;
//     this->type = obj.getType();
// 	this->dogBrain = obj.dogBrain;
//     return (*this);
// }

// deep copy
Dog &Dog::operator=(const Dog &obj)
{
	if (this == &obj)
		return (*this);
    std::cout << "Dog assinment constructor called" << std::endl;
    this->type = obj.getType();
	this->dogBrain = new Brain(*obj.dogBrain);
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog make sound 'Wal Wal'" << std::endl;
}

Brain*	Dog::getDogbrain(void) const
{
	return (this->dogBrain);
}