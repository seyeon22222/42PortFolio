#include <iostream>
#include <string>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "문자열 출력 : " << str << std::endl;
	std::cout << "메모리상 주소 출력 : " << &str << std::endl;
	std::cout << "문자열의 주소 출력(stringREF) : " << &stringREF << std::endl;
	std::cout << "문자열의 주소 출력(stringPTR) : " << stringPTR << std::endl;
	std::cout << "문자열 출력(stringREF) : " << stringREF << std::endl;
	std::cout << "문자열 출력(stringPTR) : " << *stringPTR << std::endl;
	
	return (0);
}