#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Argu Error" << std::endl;
		return (EXIT_FAILURE);
	}
	RPN	a;

	a.execute(argv[1]);
}