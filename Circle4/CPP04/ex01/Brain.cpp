#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = i;
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(void)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = i;
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	*this = obj;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "Brain assinment constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}