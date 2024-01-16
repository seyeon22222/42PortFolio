#include <iostream>
#include <cstdlib>
#include <iomanip>
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
	i = 1;
	std::vector<int> v;
	while (i < argc)
	{
		v.push_back(atoi(argv[i]));
		i++;
	}
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator itt = v.end();
	clock_t	start = clock();
	std::sort(it, itt);
	clock_t end = clock();
	std::cout << "Time to process a range of " << std::setw(4) << v.size() << " elements with std::vector  : " << end - start << " ms" << std::endl;
}