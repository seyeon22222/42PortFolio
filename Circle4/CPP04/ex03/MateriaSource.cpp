#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
	}
	// std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i])
			delete this->slot[i];
	}
	// std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	*this = obj;
	// std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i])
			delete this->slot[i];
		if (obj.slot[i])
			this->slot[i] = obj.slot[i]->clone();
		else
			this->slot[i] = 0;
	}
	// std::cout << "MateriaSource assinment constructor called" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->slot[i])
		{
			this->slot[i] = obj;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria	*temp;

	if (type == "ice")
		temp = new Ice();
	else if (type == "cure")
		temp = new Cure();
	else
		return (0);
	return (temp);
}
