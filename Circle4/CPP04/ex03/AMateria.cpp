#include "AMateria.hpp"

AMateria::AMateria(void)
{
	this->type = "default";
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &obj)
{
	*this = obj;
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	if (this == &obj)
		return (*this);
	// std::cout << "AMateria assinment constructor called" << std::endl;
	this->type = obj.clone()->getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Don't use this func " << target.getName() << std::endl;
}