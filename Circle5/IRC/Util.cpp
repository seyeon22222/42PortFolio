
#include "Util.hpp"
#include "IRCServer.hpp"
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <sstream>

void    Util::parseArgv(int argc)
{
    if (argc != 3) {
		throw std::runtime_error("Invaild Input Argumenets : <port> <password>");
	}
}

unsigned short  Util::parsePort(std::string str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!isdigit(str[static_cast<int>(i)]))
            throw std::runtime_error("Invaild Port Format");
    }
    unsigned short port = static_cast<unsigned short>(atoi(str.c_str()));
    return (port);
}

std::string Util::parsePassword(std::string str)
{
    if (str.length() > 13)
        throw std::runtime_error("Too long Password");
    return (str);
}


std::string Util::toString(size_t value) {
	std::stringstream ss;
	ss << value;
	return ss.str();
}

bool	Util::wildcard(std::string pat, std::string word)
{
	size_t	len_p = pat.length();
	size_t	len_w = word.length();
	size_t	pos;
	bool	match_flag;
	bool	dp[15][15];
	size_t		p_i = 0;
	size_t		w_i = 0;

	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	pos = -1;
	while (pat[++pos] == '*')
		dp[pos + 1][0] = dp[pos][0];
	while (++p_i <= len_p)
	{
		w_i = 0;
		while (++w_i <= len_w)
		{
			if (pat[p_i - 1] == '*')
				dp[p_i][w_i] = (dp[p_i - 1][w_i] || dp[p_i][w_i - 1]);
			else if (pat[p_i - 1] == '?' || (pat[p_i - 1] == word[w_i - 1]))
				dp[p_i][w_i] = dp[p_i - 1][w_i - 1];
		}
	}
	match_flag = dp[len_p][len_w];
	return (match_flag);
}

std::vector<std::string> Util::split(std::string const &str, std::string const &delim) {
    std::vector<std::string>	ret;
	size_t	from;
	size_t	to;

	from = 0;
	to = 0;
	while ((to = str.find(delim, from)) != std::string::npos) {
		ret.push_back(str.substr(from, to - from));
		from = to + delim.size();
	}
	if (from != str.size())
		ret.push_back(str.substr(from));
	return (ret);
}
