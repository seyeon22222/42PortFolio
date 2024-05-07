
#include "IRC.hpp"
#include "Util.hpp"

/*
RFC 1459

message = "[a-zA-Z]+ ([^: \\r\\n][^ \\r\\n]* )*(:[^\\r\\n]*)?\\r\\n)"

*/
Regex const	IRC::message_regex("[a-zA-Z]+( [^: \\r\\n][^ \\r\\n]*)*( :[^\\r\\n]*)?\\r\\n)");

#include <iostream>
std::vector<std::string>	IRC::parseMessage(std::string const &msg) {
	int	pos;
	int	count;

	if (msg == "LIST \r\n") {
		std::vector<std::string>	special_case;

		special_case.push_back("LIST");
		return (special_case);
	}
	if (Regex("( :[^\\r\\n]*)?\\r\\n").match(msg, pos, count)) {
		std::vector<std::string>	ret;
		std::vector<std::string>	body = Util::split(msg.substr(0, pos), " ");
		std::string	trailing = msg.substr(pos + 2, count - 4);
		
		for (std::vector<std::string>::const_iterator it = body.begin(); it != body.end(); ++it)
			ret.push_back(*it);
		if (trailing.size() != 0)
			ret.push_back(trailing);
		return (ret);
	}
	throw std::runtime_error("Unable to split irc message");
}