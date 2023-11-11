#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* meta_2 = new WrongAnimal();
    const WrongCat* i_2 = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    // Wrong Class
    std::cout << i_2->getType() << " " << std::endl;
    i_2->makeSound(); 
    meta_2->makeSound();

    delete meta;
    delete i;
    delete j;
    delete meta_2;
    delete i_2;
    return 0;
}
