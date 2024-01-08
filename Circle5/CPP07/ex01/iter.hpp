#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<class T, typename Func>
void iter(T &add, size_t size, Func func)
{
	for (size_t i = 0; i < size; i++)
		func(add[i]);
}

template<class T, typename Func>
void iter(T *add, size_t size, Func func)
{
	for (size_t i = 0; i < size; i++)
		func(add[i]);
}


#endif