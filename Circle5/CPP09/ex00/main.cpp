#include "BitcoinExchange.hpp"
#include <iostream>


int main(int ac , char *av[])
{
	if (ac != 2)
	{
		std::cerr << "File Not Open" << std::endl;
		return (1);
	}
	BitcoinExchange btc;

	btc.initialize(av[1]);
}