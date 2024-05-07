
#include "Lexer.hpp"
#include <stdexcept>

/*
class : [, ]
parenthesis : (, )
CHARACTER
Quantifier : +, *, ?
binary operator : |(alternation), .(concat), -(class range specifier)
*/
// expression = (prefix) ((operator) (expression))*

char	escape(char c) {
	switch (c)
	{
	case '+':
	case '*':
	case '?':
	case '|':
	case '-':
	case '(':
	case ')':
	case '[':
	case ']':
	case '^':
		return (c);
	case 'n':
		return ('\n');
	case 'r':
		return ('\r');
	case '\\':
		return ('\\');
	default:
		throw std::runtime_error("Bad escape sequence");
	}
}

Lexer::Lexer(std::string const &str) {
	std::size_t	i = 0;

	while (i < str.size()) {
		switch (str[i]) {
		case '+':
		case '*':
		case '?':
			this->tokens.push(Token(Token::QUANTIFIER, str[i]));
			break;
		case '|':
			this->tokens.push(Token(Token::ALTERNATION, str[i]));
			break;
		case '-':
			this->tokens.push(Token(Token::RANGE, str[i]));
			break;
		case '(':
			this->tokens.push(Token(Token::LPAREN, str[i]));
			break;
		case ')':
			this->tokens.push(Token(Token::RPAREN, str[i]));
			break;
		case '[':
			this->tokens.push(Token(Token::LBRACKET, str[i]));
			break;
		case '^':
			this->tokens.push(Token(Token::CARET, str[i]));
			break;
		case ']':
			this->tokens.push(Token(Token::RBRACKET, str[i]));
			break;
		case '\\':
			i += 1;
			this->tokens.push(Token(Token::CHARACTER, escape(str[i])));
			break;
		default:
			this->tokens.push(Token(Token::CHARACTER, str[i]));
			break;
		}
		i += 1;
	}
}

Token	Lexer::next(void) {
	if (this->tokens.empty())
		return (Token(Token::END, '\0'));
	Token	token = this->tokens.front();

	this->tokens.pop();
	return (token);
}

Token	Lexer::peek(void) {
	if (this->tokens.empty())
		return (Token(Token::END, '\0'));
	return (this->tokens.front());
}
