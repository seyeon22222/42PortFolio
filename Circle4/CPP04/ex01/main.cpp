#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void t()
{
	system("leaks Animal");
}

int main()
{
	Animal *arr[6];

	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	for (int i = 0; i < 6; i++)
		delete arr[i];

	Dog	Dog1;
	Dog	*dogTemp;
	dogTemp = new Dog(Dog1);
	dogTemp->getDogbrain()->printIdea(0);
	dogTemp->getDogbrain()->setIdea("hello", 0);
	std::cout << "-----------deep dog copy-----------"  << std::endl;
	dogTemp->getDogbrain()->printIdea(0);
	Dog1.getDogbrain()->printIdea(0);
	delete dogTemp;
	std::cout << "-----------------------------------"  << std::endl;
	Cat	Cat1;
	Cat	*catTemp;
	catTemp = new Cat(Cat1);
	catTemp->getCatbrain()->printIdea(0);
	catTemp->getCatbrain()->setIdea("hello", 0);
	std::cout << "-----------deep cat copy-----------"  << std::endl;
	catTemp->getCatbrain()->printIdea(0);
	Cat1.getCatbrain()->printIdea(0);
	delete catTemp;
	// atexit(t);
	return 0;
}