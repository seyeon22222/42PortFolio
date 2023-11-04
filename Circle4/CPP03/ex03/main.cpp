#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	Player1("A");
	DiamondTrap	Player2("B");
	DiamondTrap Player3("C");
	DiamondTrap Player4;
	DiamondTrap &Player5 = Player3;


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
	

	std::cout << "------------------------------------" << std::endl;
	Player5.attack("default");
	Player4.takeDamage(30);
	Player4.beRepaired(50);
	std::cout << "------------------------------------" << std::endl;
	Player4.attack("C");
	Player5.takeDamage(30);
	Player5.beRepaired(10);
	std::cout << "------------------------------------" << std::endl;
	Player5.highFivesGuys();
	Player4.highFivesGuys();
	std::cout << "------------------------------------" << std::endl;
	Player5.guardGate();
	Player4.guardGate();
	std::cout << "------------------------------------" << std::endl;
	Player5.whoAmI();
	Player4.whoAmI();
	std::cout << "------------------------------------" << std::endl;
}