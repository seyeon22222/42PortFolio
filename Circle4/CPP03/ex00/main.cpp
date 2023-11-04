#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	Player1;
	ClapTrap	Player2("Kardet");

	std::cout << "------------" << std::endl;
	Player1.attack("Kardet");
	Player1.takeDamage(1);
	Player1.takeDamage(4);
	Player1.beRepaired(5);
	std::cout << "------------" << std::endl;
	Player2.attack("default");
	Player2.takeDamage(5);
	Player2.takeDamage(5);
	Player2.beRepaired(1);
}