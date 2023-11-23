#include "Ice.hpp"

Ice::Ice(void)
{
	// std::cout << "Ice constructor called" << std::endl;
	this->type = "ice";
}

Ice::~Ice(void)
{
	// std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice (const Ice &obj)
{
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = obj;
}

Ice &Ice::operator=(const Ice &obj)
{
	if (this == &obj)
		return (*this);
	// std::cout << "Ice assinment constructor called" << std::endl;
	this->type = obj.getType();
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria	*temp = new Ice(*this);
	// std::cout << "here ice : " << temp << std::endl;
	return (temp);
}