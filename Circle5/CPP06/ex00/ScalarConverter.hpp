#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cmath>
# include <iomanip>
// static class -> 모든 인자가 static인 클래스
class ScalarConverter
{
private:
	ScalarConverter();
public:
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter &operator=(const ScalarConverter& obj);
	~ScalarConverter();
	static void convert(const std::string& input);
};

#endif