#include "Cure.hpp"

Cure::Cure(void)
{
	this->type = "cure";
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure(void)
{
	// std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &obj)
{
	// std::cout << "Cure copy constructor called" << std::endl;
	*this = obj;
}

Cure &Cure::operator=(const Cure &obj)
{
	if (this == &obj)
		return (*this);
	// std::cout << "Cure assinment constructor called" << std::endl;
	this->type = obj.getType();
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria	*temp = new Cure(*this);
	// std::cout << "here ice : " << temp << std::endl;
	return (temp);
}