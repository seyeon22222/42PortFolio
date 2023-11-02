#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>

class ScavTrap
{
private:
	std::string		name;
	unsigned int	HitPoint;
	unsigned int	EnergyPoint;
	unsigned int	AttackDamage;
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &ScavTrap);
	ScavTrap   &operator=(const ScavTrap &ScavTrap);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif