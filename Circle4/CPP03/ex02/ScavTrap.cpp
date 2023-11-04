#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->name = "default";
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
    std::cout << "ScavTrap constructor " << this->name << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
    std::cout << "ScavTrap constructor " << this->name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap)
{
    this->name = ScavTrap.name;
	this->HitPoint = ScavTrap.HitPoint;
	this->EnergyPoint = ScavTrap.EnergyPoint;
	this->AttackDamage = ScavTrap.AttackDamage;
    std::cout << "ScavTrap Copy constructor " << this->name << " called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor " << this->name << " called" << std::endl;
}

ScavTrap   &ScavTrap::operator=(const ScavTrap &ScavTrap)
{
    this->name = ScavTrap.name;
	this->HitPoint = ScavTrap.HitPoint;
	this->EnergyPoint = ScavTrap.EnergyPoint;
	this->AttackDamage = ScavTrap.AttackDamage;
    std::cout << "ScavTrap Assignment " << this->name << " called" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (!this->EnergyPoint || !this->HitPoint)
		std::cout << "ScavTrap " << this->name << " can't do this" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoint--;
	}
}
	
void ScavTrap::guardGate(void)
{
    if (!this->EnergyPoint || !this->HitPoint)
		std::cout << "ScavTrap " << this->name << " can't do this" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " guardGate"<< std::endl;
		this->EnergyPoint--;
	}
}