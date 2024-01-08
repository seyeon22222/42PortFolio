#include "BitcoinExchange.hpp"
#include <fstream>
#include <ostream>
#include <sstream>
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
	if (fstr.is_open())
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
		return (false);
	while (std::getline(temp, date, '-'))
	{
		if (idx == 0)
		{
			std::istringstream(date) >> year;
			if (year < 1000 || year > 9999)
				return (false);
		}
		else if (idx == 1)
		{
			std::istringstream(date) >> month;
			if (month < 1 || month > 12)
				return (false);
		}
		else if (idx == 2)
		{
			std::istringstream(date) >> day;
			if (day < 1 || day > 31)
				return (false);
			if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
				return (false);
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			{
				if (day > 28 && month ==2)
					return (false);
			}
			if (day > 28 && month == 2)
				return (false);
		}
		idx++;
	}
	if (idx != 3)
		return (false);	
	return (true);
}

bool BitcoinExchange::check_val(std::string str)
{
	char *ptr = 0;
	double data = std::strtod(str.c_str(), &ptr);
	if (*ptr && std::strcmp(ptr, "f"))
		return (false);
	if (data == 0.0 && !std::isdigit(str[0]))
		return (false);
	if (data < 0)
		return (false);
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
	
}