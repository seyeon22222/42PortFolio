#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "defalut";
	this->HitPoint = 10;
	this->EnergyPoint = 10;
	this->AttackDamage = 0;
	std::cout << "ClapTrap constructor " << this->name << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->HitPoint = 10;
	this->EnergyPoint = 10;
	this->AttackDamage = 0;
	std::cout << "ClapTrap constructor " << this->name << " called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor " << this->name << " called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ClapTrap)
{
	this->name = ClapTrap.name;
	this->HitPoint = ClapTrap.HitPoint;
	this->EnergyPoint = ClapTrap.EnergyPoint;
	this->AttackDamage = ClapTrap.AttackDamage;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap   &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
	this->name = ClapTrap.name;
	this->HitPoint = ClapTrap.HitPoint;
	this->EnergyPoint = ClapTrap.EnergyPoint;
	this->AttackDamage = ClapTrap.AttackDamage;
	std::cout << "ClapTrap operator = called" << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->EnergyPoint || !this->HitPoint)
		std::cout << "ClapTrap " << this->name << " can't do this" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " has damaged " << amount << " points !" << std::endl;
	if (this->HitPoint < amount)
		this->HitPoint = 0;
	else
		this->HitPoint -= amount;
	if (this->HitPoint == 0)
		std::cout << "ClapTrap " << this->name << " has died!" << std::endl;

}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->EnergyPoint || !this->HitPoint)
		std::cout << "ClapTrap " << this->name << " is not enough energy!" << std::endl;
	else
	{
		this->HitPoint += amount;
		std::cout << "ClapTrap " << this->name << " has repaired " << amount << " points !" 
		<< " So " << this->name << " has " << this->HitPoint << " point!" << std::endl;
		this->EnergyPoint--;
	}
}