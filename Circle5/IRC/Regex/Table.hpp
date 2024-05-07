
#ifndef TABLE_HPP
# define TABLE_HPP

# include "AST.hpp"
# include <vector>
# include <set>
# include <map>

class Table {
public:
	Table(AST const	&ast);

public:
	std::vector<bool>	nullable;
	std::vector<std::set<int> >	first;
	std::vector<std::set<int> >	last;
	std::map<int, std::set<int> >	follow;
	void	computeNullable(AST const &ast);
	void	computeFirst(AST const &ast);
	void	computeLast(AST const &ast);
	void	computeFollow(AST const &ast);
};

#endif
