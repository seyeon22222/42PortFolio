#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	Player1("A");
	DiamondTrap	Player2("B");


	std::cout << "------------------------------------" << std::endl;
	Player1.attack("B");
	Player2.takeDamage(30);
	Player2.beRepaired(50);
	std::cout << "------------------------------------" << std::endl;
	Player2.attack("A");
	Player1.takeDamage(30);
	Player1.beRepaired(10);
	std::cout << "------------------------------------" << std::endl;
	Player1.highFivesGuys();
	Player2.highFivesGuys();
	std::cout << "------------------------------------" << std::endl;
	Player1.guardGate();
	Player2.guardGate();
	std::cout << "------------------------------------" << std::endl;
	Player1.whoAmI();
	Player2.whoAmI();
	std::cout << "------------------------------------" << std::endl;
}