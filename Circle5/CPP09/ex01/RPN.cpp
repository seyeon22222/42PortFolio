#include "RPN.hpp"
#include <iostream>

RPN::RPN() : res()
{
}

RPN::RPN(std::stack<double> val)
{
	res = val;
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& obj) 
{
	*this = obj;
}

RPN &RPN::operator=(const RPN& obj)
{
	this->res = obj.res;
	return (*this);
}

void RPN::calculate(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char temp = input[i];
		if (temp == ' ')
			continue;
		else if (std::isdigit(temp))
		{
			int val = temp - '0';
			res.push(val);
		}
		else if (temp == '+' && res.size() >= 2)
		{
			double a = res.top();
			res.pop();
			double b = res.top();
			res.pop();
			res.push(a + b);
		}
		else if (temp == '-' && res.size() >= 2)
		{
			double b = res.top();
			res.pop();
			double a = res.top();
			res.pop();
			res.push(a - b);
		}
		else if (temp == '*' && res.size() >= 2)
		{
			double a = res.top();
			res.pop();
			double b = res.top();
			res.pop();
			res.push(a * b);
		}
		else if (temp == '/' && res.size() >= 2)
		{
			double b = res.top();
			res.pop();
			double a = res.top();
			res.pop();
			if (b == 0)
			{
				throw RPNError();
			}
			res.push(a / b);
		}
		else
		{
			throw RPNError();
		}
	}
	std::cout << res.top() << std::endl;
}

void RPN::execute(char *input)
{
	try
	{
		std::string str = input;
		calculate(str);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

const char *RPN::RPNError::what() const throw()
{
	return ("Error");
}