#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>

class BitcoinExchange
{
private:
	std::map<std::string, float> val;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	BitcoinExchange &operator=(const BitcoinExchange& obj);
	~BitcoinExchange();
	void check_csv();
	void check_input(char *file);
	bool check_date(std::string);
	bool check_val(std::string);
	void initialize(char *file);
	class BitError : public std::exception
	{
		public:
			const char * what(void) const throw();
	};
};


#endif