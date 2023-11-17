#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->name = "default";
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
    std::cout << "ScavTrap constructor " << this->getName() << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
    std::cout << "ScavTrap constructor " << this->getName() << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap)
{
    *this = ScavTrap;
    std::cout << "ScavTrap Copy constructor " << this->getName() << " called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor " << this->getName() << " called" << std::endl;
}

ScavTrap   &ScavTrap::operator=(const ScavTrap &ScavTrap)
{
	if (this == &ScavTrap)
		return (*this);
    this->name = ScavTrap.name;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
    std::cout << "ScavTrap Assignment " << this->getName() << " called" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (!this->getEnergy() || !this->getHit())
		std::cout << "ScavTrap " << this->getName() << " can't do this" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttack() << " points of damage!" << std::endl;
		this->EnergyPoint--;
	}
}
	
void ScavTrap::guardGate(void)
{
    if (!this->getEnergy() || !this->getHit())
		std::cout << "ScavTrap " << this->getName() << " can't do this" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->getName() << " guardGate"<< std::endl;
		this->EnergyPoint--;
	}
}
