#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	//abstract class라서 인스턴스 생성이 불가능
	// AAnimal	*AA = new AAnimal();
	Animal	*_Dog = new Dog();
	Animal	*_Cat = new Cat();
	
	_Dog->makeSound();
	_Cat->makeSound();

	delete _Dog;
	delete _Cat;
	return 0;
}