
#ifndef IRC_HPP
# define IRC_HPP

# include <vector>
# include <string>
# include "Regex/Regex.hpp"

class IRC {
public:
	static Regex const	message_regex;
	//([a-zA-Z]+|[0-9][0-9][0-9]) : <command>
	// ([^: \0\r\n][^ \0\r\n]* )*(:[^\0\r\n]*)? : <params>
	//([a-zA-Z]+|[0-9][0-9][0-9]) ([^: \0\r\n][^ \0\r\n]* )*(:[^\0\r\n]*)?\r\n : <message>
	static std::vector<std::string>	parseMessage(std::string const	&msg);
private:
IRC();
};

#endif
