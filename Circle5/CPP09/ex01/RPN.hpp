#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
class RPN
{
private:
	std::stack<double>	res;
public:
	RPN();
	~RPN();
	RPN(std::stack<double> val);
	RPN(const RPN& obj);
	RPN &operator=(const RPN& obj);
	void execute(char *input);
	void calculate(std::string input);
	class RPNError : public std::exception
	{
		public:
			const char * what(void) const throw();
	};
};

#endif