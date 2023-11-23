#include "Character.hpp"

Character::Character(void)
{
	this->name = "default";
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
		this->trash[i] = NULL;
	}
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
		this->trash[i] = NULL;
	}
}

Character::Character(const Character &obj)
{
	*this = obj;
	
}

Character &Character::operator=(const Character &obj)
{
	if (this == &obj)
		return (*this);
	this->name = obj.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (obj.inventory[i])
			this->inventory[i] = obj.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
		if (this->trash[i])
			delete this->trash[i];
		if (obj.trash[i])
			this->trash[i] = obj.trash[i]->clone();
		else
			this->trash[i] = NULL;
	}
	return (*this);
	
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->trash[i])
			delete this->trash[i];
		if (this->inventory[i])
			delete this->trash[i];
	}
}

std::string const& Character::getName(void) const
{
	return (this->name);
}

void Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx] == NULL)
	{
		std::cout << "Please equip Materia in this slot : " << idx << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "Too Many equip" << std::endl;
}

void Character::unequip(int idx)
{
	if (this->inventory[idx])
	{
		this->trash[idx] = this->inventory[idx];
		this->inventory[idx] = 0;
		std::cout << "Unequip Materia : " << idx << std::endl;
	}
}

void	Character::printInventory(void)
{
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			std::cout << inventory[i]->getType() << std::endl;
}