
#ifndef TOKEN_HPP
# define TOKEN_HPP

struct Token {
	enum Type {
		INVALID,
		CHARACTER,
		QUANTIFIER,
		ALTERNATION,
		LPAREN,
		RPAREN,
		LBRACKET,
		RBRACKET,
		RANGE,
		CARET,
		END
	};
	Type	type;
	char	symbol;
	Token(Type type, char symbol);
	// rule of three
};

#endif
