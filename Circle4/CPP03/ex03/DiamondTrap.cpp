#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : name(ClapTrap::name)
{
    ClapTrap::name = name + "_clap_name";
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 30;
    std::cout << "DiamondTrap constructor " << this->name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    this->name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 30;
    ClapTrap::name = name + "_clap_name";
    std::cout << "DiamondTrap constructor " << this->name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor " << this->name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap)
{
    this->name = DiamondTrap.name;
	this->HitPoint = DiamondTrap.HitPoint;
	this->EnergyPoint = DiamondTrap.EnergyPoint;
	this->AttackDamage = DiamondTrap.AttackDamage;
    std::cout << "DiamondTrap Copy constructor " << this->name << " called" << std::endl;
}

DiamondTrap   &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
    this->name = DiamondTrap.name;
	this->HitPoint = DiamondTrap.HitPoint;
	this->EnergyPoint = DiamondTrap.EnergyPoint;
	this->AttackDamage = DiamondTrap.AttackDamage;
    std::cout << "DiamondTrap Assignment " << this->name << " called" << std::endl;
    return (*this);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap Name : " << this->name 
	<< std::endl <<"ClapTrap Name : " << ClapTrap::name << std::endl;
}
