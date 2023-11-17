#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->name = "default";
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
    std::cout << "FragTrap constructor " << this->getName() << " called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
    std::cout << "FragTrap constructor " << this->getName() << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap)
{
    *this = FragTrap;
    std::cout << "FragTrap Copy constructor " << this->getName() << " called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor " << this->getName() << " called" << std::endl;
}

FragTrap   &FragTrap::operator=(const FragTrap &FragTrap)
{
	if (this == &FragTrap)
		return (*this);
    this->name = FragTrap.name;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
    std::cout << "FragTrap Assignment " << this->getName() << " called" << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    if (!this->getHit() || !this->getEnergy())
        std::cout << this->getName() << "is not enough energy" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->getName() << " highFivesGuys" << std::endl;
        this->EnergyPoint--;
    }
}