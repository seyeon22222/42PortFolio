
#ifndef REGEX_HPP
# define REGEX_HPP

# include <algorithm>
# include <string>
# include <queue>
# include "DFA.hpp"

class Regex {
public:
	Regex();
	Regex(std::string const &pattern);
	~Regex();
	Regex	&operator=(Regex other);
	bool	match(std::string const &str) const;
	bool	match(std::string const &str, int &pos, int &count) const;
	static bool	match(std::string const &pattern, std::string const &str);
private:
	DFA	dfa;
};

#endif
