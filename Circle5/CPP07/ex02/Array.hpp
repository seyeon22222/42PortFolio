#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
private:
	T		*arr;
	int		t_size;

public:
	Array() : t_size(0)
	{
		arr = new T[0];
	}

	~Array()
	{
		delete [] arr;
	}

	Array(unsigned int n) : t_size(n)
	{
		arr = new T[n];
	}

	Array(const Array& obj)
	{
		arr = NULL;
		*this = obj;
	}

	Array &operator=(const Array& obj)
	{
		if (arr != NULL)
			delete [] arr;
		if (obj.size() != 0)
		{
			t_size = obj.size();
			arr = new T[t_size];
			for (int i = 0; i < t_size; i++)
				arr[i] = obj.arr[i];
		}
		return (*this);
	}

	T& operator[](int n)
	{
		if (n >= t_size || n < 0)
		{
			throw Array<T>::ArrayException();
		}
		return (arr[n]);
	}

	size_t	size() const
	{
		return (t_size);
	}
	
	class ArrayException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};
};

template<class T>
const char* Array<T>::ArrayException::what() const throw()
{
	return ("Not allocate memory");
}



#endif