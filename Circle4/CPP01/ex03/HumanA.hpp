#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		Weapon	&weapon;
		std::string	name;
	public:
		HumanA(std::string	name, Weapon &weapon);
		~HumanA(void);
		void	attack(void);
};

#endif