#include "iter.hpp"
#include <iostream>

template<class T>
void print(T a)
{
	std::cout << a << std::endl;
}

int main()
{
	int  i[5] = { 1, 2, 3, 4, 5 };
	iter(i, 5, print<int>);
	std::cout << "-----------char------------" << std::endl;
	char b[5] = {'1', '2', '3', '4', '5'};
	iter(b, 5, print<char>);
	std::cout << "----------string-----------" << std::endl;
	std::string c = "hello world";
	iter(c, c.size(), print<char>);
}

