
#ifndef UTIL_HPP
# define UTIL_HPP

# include <string>


class Util{
public:
    static void             		parseArgv(int argc);
    static unsigned short   		parsePort(std::string str);
    static std::string      		parsePassword(std::string str);
	static std::string 				toString(size_t value);
	static bool						wildcard(std::string pat, std::string word);
	static std::vector<std::string> split(std::string const &str, std::string const &delim);
private:
    Util() {}
    ~Util() {}
};


#endif