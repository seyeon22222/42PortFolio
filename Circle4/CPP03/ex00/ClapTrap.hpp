#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	HitPoint;
	unsigned int	EnergyPoint;
	unsigned int	AttackDamage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &ClapTrap);
	ClapTrap   &operator=(const ClapTrap &ClapTrap);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string const &getName(void) const;
	unsigned int const &getHit(void) const;
	unsigned int const &getEnergy(void) const;
	unsigned int const &getAttack(void) const;
	void	setName(std::string name);
	void	setHit(unsigned int amount);
	void	setEnergy(unsigned int amount);
	void	setAttack(unsigned int amount);
};

#endif