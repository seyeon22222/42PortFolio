#include "BitcoinExchange.hpp"
#include <fstream>
#include <ostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : val()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	val = obj.val;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	val = obj.val;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::check_csv()
{
	std::ifstream csv("data.csv");
	std::string buf;
	size_t buf_size;
	float	data;

	if (!csv)
	{
		std::cout << "Error: No file to CSV" << std::endl;
		throw BitError();
	}
	if (std::getline(csv, buf).eof())
	{
		std::cout << "Error: empty file" << std::endl;
		throw BitError();
	}
	while (std::getline(csv, buf))
	{
		if (buf != "date,exchange_rate")
		{
			buf_size = buf.find(",");
			if (check_date(buf.substr(0, buf_size)) ==  false)
			{
				std::cout << "Error: invalid date" << std::endl;
				throw BitError();
			}
			if (check_val(buf.substr(buf_size + 1, buf.length())) == false)
			{
				std::cout << "Error: too large a number" << std::endl;
				throw BitError();
			}
			std::istringstream(buf.substr(buf_size + 1, buf.length())) >> data;
			val[buf.substr(0, buf_size)] = data;
		}
	}
}

void BitcoinExchange::check_input(char *file)
{
	std::fstream fstr;
	std::string str;

	fstr.open(file, std::ifstream::in);
	if (fstr.is_open() == 0)
	{
		std::cout << "Error: Not correct file" << std::endl;
		throw BitError();
	}

	if (std::getline(fstr, str).eof())
	{
		std::cout << "Error: Empty Input File" << std::endl;
		throw BitError();
	}

	if (str.compare("date | value") != 0)
	{
		std::cout << "Error: Input Format Error" << std::endl;
		throw BitError();
	}
	str.erase();
	fstr.close();
}

bool BitcoinExchange::check_date(std::string str)
{
	std::string date;
	std::istringstream temp(str);
	int year, month, day;
	int idx = 0;
	
	if (str.length() != 10)
	{
		std::cout << "Not Correct Format => " << str << std::endl;
		return (false);
	}
	while (std::getline(temp, date, '-'))
	{
		if (idx == 0)
		{
			std::istringstream(date) >> year;
			if (year < 1000 || year > 9999)
			{
				std::cout << "Not Correct Year Format => " << str << std::endl;
				return (false);
			}
		}
		else if (idx == 1)
		{
			std::istringstream(date) >> month;
			if (month < 1 || month > 12)
			{
				std::cout << "Not Correct Month Format => " << str << std::endl;
				return (false);
			}
		}
		else if (idx == 2)
		{
			std::istringstream(date) >> day;
			if (day < 1 || day > 31)
			{
				std::cout << "Not Correct Day Format => " << str << std::endl;
				return (false);
			}
			if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
			{
				std::cout << "Invaild date => " << str << std::endl;
				return (false);
			}
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			{
				if (day > 28 && month ==2)
				{
					std::cout << "Invaild date => " << str << std::endl;
					return (false);
				}
			}
			if (day > 28 && month == 2)
			{
				std::cout << "Invaild date => " << str << std::endl;
				return (false);
			}
		}
		idx++;
	}
	if (idx != 3)
	{
		std::cout << "Invaild Format => " << str << std::endl;
		return (false);	
	}
	return (true);
}

bool BitcoinExchange::check_val(std::string str)
{
	char *ptr = 0;
	double data = std::strtod(str.c_str(), &ptr);
	if (str.find('.', 0) == 0 || str.find('.', str.length() - 1) != std::string::npos)
	{
		std::cout << "Error: not a number" << std::endl;
		return (false);
	}
	if (*ptr && std::strcmp(ptr, "f"))
	{
		std::cout << "Error: not a number" << std::endl;
		return (false);
	}
	if (data == 0.0 && !std::isdigit(str[0]))
	{
		std::cout << "Error: not a number" << std::endl;
		return (false);
	}
	if (data < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return (false);
	}
	if (str.length() > 10 || (str.length() == 10 && data > INT_MAX))
	{
		std::cout << "Error: too large a number" << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::initialize(char *file)
{
	try
	{
		check_csv();
		check_input(file);
	}
	catch(...)
	{
		return ;
	}
	execute(file);
}

void BitcoinExchange::execute(char *file)
{
	std::ifstream readfile(file);
	std::string buf;
	getline(readfile, buf);
	while (getline(readfile, buf))
	{
		checkInfo(buf);
	}
}

void BitcoinExchange::checkInfo(std::string buf)
{
	std::string date, str;
	std::istringstream format(buf);
	float data;
	int idx = 0;

	while (std::getline(format, str, ' '))
	{
		if (idx == 0)
		{
			if (check_date(str) == 0)
				return ;
			date = str;
		}
		else if (idx == 1 && str != "|")
		{
			std::cout << "Not Correct Format => " << buf << std::endl;
			return ;
		}
		else if (idx == 2)
		{
			if (check_val(str) == 0)
				return ;
			data = std::strtod(str.c_str(), NULL);
			if (data > 1000)
			{
				std::cout << "Error: too large a number" << std::endl;
				return ;
			}
		}
		idx++;
	}
	if (idx != 3)
	{
		std::cout << "Not Correct Format => " << buf << std::endl;
		return ;
	}
	printData(date, data);
}

void BitcoinExchange::printData(std::string date, float data)
{
	std::map<std::string, float>::const_iterator iter;
	float res = 0;

	iter = val.find(date);
	if (iter != val.end())
		res = iter->second * data;
	else
	{
		iter = val.lower_bound(date);
		if (iter == val.begin())
		{
			std::cout << "Invaild Date" << std::endl;
			return ;
		}
		--iter;
		res = (iter->second) * data;
	}
	if (data == static_cast<int>(data))
		std::cout << date << " => " << static_cast<int>(data) << " = " << res << std::endl;
	else
		std::cout << date << " => " << data << " = " << res << std::endl;
}

const char* BitcoinExchange::BitError::what(void) const throw()
{
	return ("Error\n");
}