#include "Brain.hpp"

Brain::Brain(void)
{
	fillBrain("default");
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
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

void Brain::fillBrain(std::string type)
{
	std::string numset = "0123456789abcedf";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = type + numset[i % 16];
}

void	Brain::printIdea(int num)
{
	std::cout << "Idea : " << this->ideas[num] << std::endl;
}

void	Brain::setIdea(std::string str, int num)
{
	this->ideas[num] = str;
}