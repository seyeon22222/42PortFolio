#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	Player1("A");
	ScavTrap	Player2("B");

	std::cout << "------------------------------------" << std::endl;
	Player1.attack("B");
	Player2.takeDamage(20);
	Player2.beRepaired(5);
	std::cout << "------------------------------------" << std::endl;
	Player2.attack("A");
	Player1.takeDamage(20);
	Player1.beRepaired(1);
	std::cout << "------------------------------------" << std::endl;
	Player1.guardGate();
	Player2.guardGate();
	std::cout << "------------------------------------" << std::endl;
}