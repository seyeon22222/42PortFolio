#include <iostream>
#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	int i = 1;
	PmergeMe a;
	while (i < argc)
	{
		a.push(argv[i]);
		i++;
	}
	a.display();
}