#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::vector<int> a;

	for (int i = 0; i < 5; i++)
		a.push_back(i);
	try
	{
		std::vector<int>::iterator iter = easyfind(a, 3);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::vector<int>::iterator iter2 = easyfind(a, 10);
		std::cout << *iter2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "-------------Deque--------------" << std::endl;	
	std::deque<int> c;

	for (int i = 0; i < 5; i++)
		c.push_back(i);
	try
	{
		std::deque<int>::iterator iter = easyfind(c, 3);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		std::deque<int>::iterator iter2 = easyfind(c, 10);
		std::cout << *iter2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}