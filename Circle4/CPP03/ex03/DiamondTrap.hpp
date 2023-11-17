#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
    DiamondTrap(void);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
	DiamondTrap(const DiamondTrap &DiamondTrap);
	DiamondTrap   &operator=(const DiamondTrap &DiamondTrap);
	std::string getName(void) const;
	void	setName(std::string name);
	void	whoAmI(void);
};

#endif