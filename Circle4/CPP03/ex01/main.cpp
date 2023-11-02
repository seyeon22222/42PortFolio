#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	Player1;
	ClapTrap	Player2("Kardet");

	Player1.attack("Kardet");
	Player2.takeDamage(1);
	Player2.takeDamage(4);
	Player2.beRepaired(5);
	Player2.attack("default");
	Player2.takeDamage(5);
	Player2.takeDamage(5);
	Player2.beRepaired(1);
}