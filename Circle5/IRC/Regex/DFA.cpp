
#include "DFA.hpp"
#include "Table.hpp"
#include <algorithm>

DFA::Iterator::Iterator(DFA const *dfa) : dfa(dfa) {
	state_id = dfa->initial_id;
}

DFA::Iterator::Iterator() : dfa(NULL), state_id(-1) {}

DFA::Iterator::Iterator(DFA const *dfa, int state_id) : dfa(dfa), state_id(state_id) {}

DFA::Iterator::Iterator(Iterator const &other) : dfa(other.dfa), state_id(other.state_id) {}

DFA::Iterator::~Iterator() {}

DFA::Iterator	&DFA::Iterator::operator=(Iterator other) {
	std::swap(this->dfa, other.dfa);
	std::swap(this->state_id, other.state_id);
	return (*this);
}

DFA::Iterator	DFA::Iterator::operator[](char c) const {
	if (this->state_id == -1)
		return (Iterator());
	State const	&state = dfa->states[state_id];
	int			next_id = state.next[(int)c];

	return (Iterator(this->dfa, next_id));
}

DFA::State const	&DFA::Iterator::operator*(void) const {
	return (this->dfa->states[this->state_id]);
}

DFA::State const	*DFA::Iterator::operator->(void) const {
	return (&this->dfa->states[this->state_id]);
}

DFA::Iterator::operator bool() const {
	return (this->state_id != -1);
}

DFA::State::State() {
	for (int i = 0; i < 128; i++)
		this->next[i] = -1;
	this->is_final = false;
}

//--------------DFA

DFA::DFA() : initial_id(-1) {}

DFA::DFA(AST const &ast) {
	Table	table(ast);
	std::set<int> const	&initial = table.first[ast.getRoot()];

	this->initial_id = this->createState(ast, table, initial);
}

bool	DFA::has(std::set<int> const &id) const {
	return (this->state_id.count(id) == 1);
}

int	DFA::allocateState(std::set<int> const &name) {
	int const	id = this->states.size();
	this->state_id[name] = id;
	this->states.push_back(State());

	return (id);
}

int	DFA::createState(AST const &ast, Table &table, std::set<int> const &name) {
	int id = this->allocateState(name);

	if (name.count(ast.getEnd()) != 0)
		this->states[id].is_final = true;
	for (int c = 0; c < 128; c++) {
		std::set<int>	next;
		
		for (std::set<int>::iterator it = name.begin(); it != name.end(); ++it) {
			int const	leaf_id = *it;
			if (!ast[leaf_id].included[c])
				continue ;
			std::set<int> const	&leaf_follow = table.follow[leaf_id];
			next.insert(leaf_follow.begin(), leaf_follow.end());
		}
		if (next.empty())
			this->states[id].next[(int)c] = -1; // INVALID
		else if (this->has(next))
			this->states[id].next[(int)c] = (*this)[next];
		else {
			int iid = this->createState(ast, table, next);
			this->states[id].next[(int)c] = iid;
		}
	}
	return (id);
}

int	DFA::operator[](std::set<int> const &name) {
	std::map<std::set<int>, int>::const_iterator	id_iter = this->state_id.find(name);

	return (id_iter->second);
}

DFA::iterator	DFA::initial(void) const {
	return (Iterator(this));
}

int	DFA::operator[](std::set<int> const &name) const {
	std::map<std::set<int>, int>::const_iterator	id_iter = this->state_id.find(name);

	return (id_iter->second);
}
