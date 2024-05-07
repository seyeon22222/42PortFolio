
#ifndef DFA_HPP
# define DFA_HPP

# include <map>
# include <set>
# include <vector>
# include "AST.hpp"
# include "Table.hpp"

class DFA {
public:
	struct State {
		int	next[128];
		bool	is_final;
		State();
	};
	class Iterator {
	public:
		Iterator();
		Iterator(DFA const *dfa);
		Iterator(Iterator const &other);
		~Iterator();
		Iterator	&operator=(Iterator other);
		Iterator	operator[](char c) const;
		State const	&operator*(void) const;
		State const	*operator->(void) const;
		operator	bool() const;
	private:
		Iterator(DFA const *dfa, int state_id);
		DFA	const *dfa;
		int	state_id;
	};
	DFA();
	DFA(AST const &ast);
	bool	has(std::set<int> const &id) const;
	int	operator[](std::set<int> const &id) const;
	typedef Iterator	iterator;
	iterator	initial(void) const;
private:
	std::map<std::set<int>, int> state_id;
	std::vector<State>	states;
	int	initial_id;
	
	int	operator[](std::set<int> const &id);
	int	allocateState(std::set<int> const &id);
	int	createState(AST const &ast, Table &table, std::set<int> const &name);
};

#endif
