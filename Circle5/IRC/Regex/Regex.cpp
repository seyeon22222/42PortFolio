
#include "Regex.hpp"
#include "Lexer.hpp"
#include "AST.hpp"
#include "DFA.hpp"

Regex::Regex() {}

Regex::Regex(std::string const &pattern) {
	Lexer	lexer(pattern);
	AST		ast(lexer);

	this->dfa = DFA(ast);
}

Regex::~Regex() {}

Regex	&Regex::operator=(Regex other) {
	std::swap(this->dfa, other.dfa);
	return (*this);
}

bool	Regex::match(std::string const	&str) const {
	DFA::iterator	it = this->dfa.initial();
	if (it->is_final)
		return (true);
	for (std::string::const_iterator cp = str.begin(); cp != str.end(); ++cp) {
		if (it[*cp])
			it = it[*cp];
		else
			it = this->dfa.initial();
		if (it->is_final)
			return (true);
	}
	return (false);
}

bool	Regex::match(std::string const &str, int &pos, int &count) const {
	DFA::iterator	it = this->dfa.initial();
	int	t_pos = 0;
	int	t_count = 0;

	if (it->is_final)
		return (pos = 0, count = 0, true);
	for (std::string::const_iterator cp = str.begin(); cp != str.end(); ++cp) {
		if (it[*cp]) {
			it = it[*cp];
			t_count += 1;
		} else {
			it = this->dfa.initial();
			t_pos += t_count + 1;
			t_count = 0;
		}
		if (it->is_final)
			return (pos = t_pos, count = t_count, true);
	}
	return (false);
}

bool	Regex::match(std::string const &pattern, std::string const &str) {
	Regex	regex(pattern);

	return (regex.match(str));
}
