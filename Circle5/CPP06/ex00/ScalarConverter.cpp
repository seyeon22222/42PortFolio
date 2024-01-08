#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj) 
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& obj) 
{
	if (this == &obj)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input)
{
	double value;
	try
	{
		char *str = NULL;
		//strtod -> 첫번째 인자를 double값으로 변경
		//에러 발생 시, 두번째 인자에 에러가 발생한 부분을 리턴
		value = std::strtod(input.c_str(), &str);
		if (value == 0.0 && (input[0] != '-' 
		&& input[0] != '+' && !std::isdigit(input[0])) 
		&& (*str && std::strcmp(str, "f")))
			throw std::bad_alloc();
	}
	catch(...)
	{
		std::cout << "Convert Fail" << std::endl;
		return ;
	}
	std::cout << "Char : ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else
	{
		if (std::isprint(static_cast<char>(value)))
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl; 
		else
			std::cout << "Non displayable" << std::endl;
	}

	std::cout << "Int : ";
	if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	if (std::isnan(value) || std::isinf(value))
	{
		//std::showpos -> + or - 를 출력해줌
		std::cout << "Float : " << std::showpos << static_cast<float>(value) << "f" << std::endl;
		std::cout << "Double : "<< std::showpos << static_cast<double>(value) << std::endl;
		return ;
	}
	// 정밀도를 위해서 int가 아닌 int64_t(64비트)로 형변환을 해준것
	if (static_cast<float>(value) == static_cast<int64_t>(value))
		std::cout << "Float : " << static_cast<float>(value) << ".0f" << std::endl;
	else
		// setprecision -> 소수점 정밀도를 설정할 수 있는 부분
		// numeric_limits<float>을 통해서 float형의 자릿수를 반환받으며
		// ::digits10을 통해 10진수로 표현하겠다는것을 의미
		std::cout << "Float :" << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(value) << "f" << std::endl;
	if (static_cast<double>(value) == static_cast<int64_t>(value))
		std::cout << "Double : " << static_cast<double>(value) << ".0" << std::endl;
	else
		std::cout << "Double :" << std::setprecision(std::numeric_limits<double>::digits10) << static_cast<double>(value) << std::endl;
}