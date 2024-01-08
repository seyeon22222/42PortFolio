#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<class T>
void swap(T &A, T &B)
{
	T	temp;
	temp = A;
	A = B;
	B = temp;
}

template<class T>
T min(T A, T B)
{
	return (A > B ? B : A);
}

template<class T>
T max(T A, T B)
{
	return (A > B ? A : B);
}

#endif