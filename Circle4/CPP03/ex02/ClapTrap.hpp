#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	HitPoint;
	unsigned int	EnergyPoint;
	unsigned int	AttackDamage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	virtual ~ClapTrap(void);
	ClapTrap(const ClapTrap &ClapTrap);
	ClapTrap   &operator=(const ClapTrap &ClapTrap);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string const &getName(void) const;
	unsigned int const &getHit(void) const;
	unsigned int const &getEnergy(void) const;
	unsigned int const &getAttack(void) const;
};

#endif