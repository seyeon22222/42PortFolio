#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<class T>
typename T::iterator easyfind(T a, int b)
{
	typename T::iterator target = std::find(a.begin(), a.end(), b);
	if (target == a.end())
		throw std::exception();
	return (target);
}

#endif