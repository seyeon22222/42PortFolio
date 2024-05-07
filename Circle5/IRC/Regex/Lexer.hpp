
#ifndef LEXER_HPP
# define LEXER_HPP

# include <string>
# include <queue>
# include "Token.hpp"

class Lexer {
	public:
		Lexer(std::string const &str);
		Token	next(void);
		Token	peek(void);
	private:
		std::queue<Token>	tokens;
	};

#endif
