#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : name(ClapTrap::getName())
{
	ClapTrap::name = this->getName() + "_clap_name";
	this->HitPoint = FragTrap::HitPoint;
	this->EnergyPoint = ScavTrap::EnergyPoint;
	this->AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap constructor 12 " << this->getName() << " called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->setName(name);
	this->HitPoint = FragTrap::HitPoint;
	this->EnergyPoint = ScavTrap::EnergyPoint;
	this->AttackDamage = FragTrap::AttackDamage;
    ClapTrap::name = name + "_clap_name";
    std::cout << "DiamondTrap constructor " << this->getName() << " called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor " << this->getName() << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap)
{
    *this = DiamondTrap;
    std::cout << "DiamondTrap Copy constructor " << this->getName() << " called" << std::endl;
}

DiamondTrap   &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
    this->setName(DiamondTrap.getName());
	this->HitPoint = DiamondTrap.HitPoint;
	this->EnergyPoint = DiamondTrap.EnergyPoint;
	this->AttackDamage = DiamondTrap.AttackDamage;
    std::cout << "DiamondTrap Assignment " << this->getName() << " called" << std::endl;
    return (*this);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap Name : " << this->getName() 
	<< std::endl <<"ClapTrap Name : " << ClapTrap::getName()
	<< std::endl <<"ScavTrap Name : " << ScavTrap::getName()
	<< std::endl <<"FragTrap Name : " << FragTrap::getName() << std::endl;
}

std::string DiamondTrap::getName(void) const
{
	return (this->name);
}

void	DiamondTrap::setName(std::string name)
{
	this->name = name;
}