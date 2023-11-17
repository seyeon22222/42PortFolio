#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap *Player1 = new DiamondTrap("A");
	ClapTrap *Player2 = new DiamondTrap("B");


	std::cout << "------------------------------------" << std::endl;
	Player1->attack(Player2->getName());
	Player2->takeDamage(Player1->getAttack());
	Player2->beRepaired(50);
	std::cout << "------------------------------------" << std::endl;
	Player2->attack(Player2->getName());
	Player1->takeDamage(Player1->getAttack());
	Player1->beRepaired(10);
	std::cout << "------------------------------------" << std::endl;
	//dynamic_cast -> 안전한 다운캐스팅을 위한 연산자
	DiamondTrap *a = dynamic_cast<DiamondTrap *>(Player1);
	DiamondTrap *b = dynamic_cast<DiamondTrap *>(Player2);
	a->highFivesGuys();
	b->highFivesGuys();
	std::cout << "------------------------------------" << std::endl;
	a->guardGate();
	b->guardGate();
	std::cout << "------------------------------------" << std::endl;
	a->whoAmI();
	b->whoAmI();
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Player1 Energy : " << Player1->getEnergy() << std::endl;
	std::cout << "Player2 Energy : " << Player2->getEnergy() << std::endl;

	delete Player1;
	delete Player2;
	return 0;
}