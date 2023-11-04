#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->name = "default";
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
    std::cout << "FragTrap constructor " << this->name << " called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
    std::cout << "FragTrap constructor " << this->name << " called" << std::endl;
}
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor " << this->name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap)
{
    this->name = FragTrap.name;
	this->HitPoint = FragTrap.HitPoint;
	this->EnergyPoint = FragTrap.EnergyPoint;
	this->AttackDamage = FragTrap.AttackDamage;
    std::cout << "FragTrap copy constructor " << this->name << " called" << std::endl;
}

FragTrap   &FragTrap::operator=(const FragTrap &FragTrap)
{
    this->name = FragTrap.name;
	this->HitPoint = FragTrap.HitPoint;
	this->EnergyPoint = FragTrap.EnergyPoint;
	this->AttackDamage = FragTrap.AttackDamage;
    std::cout << "FragTrap Assignment " << this->name << " called" << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    if (!this->HitPoint || !this->EnergyPoint)
        std::cout << this->name << "is not enough energy" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->name << " highFivesGuys" << std::endl;
        this->EnergyPoint--;
    }
}