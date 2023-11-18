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
	const Animal *arr[100];
	
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			arr[i] = new Dog();
		}
		else
		{
			arr[i] = new Cat();
		}
	}

	for (int i = 0; i < 100; i++)
	{
		delete arr[i];
	}
	atexit(t);
	return 0;
}