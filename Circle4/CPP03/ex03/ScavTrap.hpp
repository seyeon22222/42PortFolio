#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &ScavTrap);
	ScavTrap   &operator=(const ScavTrap &ScavTrap);
	void attack(const std::string& target);
	void guardGate(void);
};


#endif