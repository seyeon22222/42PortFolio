
#ifndef AST_HPP
# define AST_HPP

# include "Lexer.hpp"
# include <bitset>

class AST {
public:
	struct Node {
		enum Type {
			LEAF,
			QUANTIFIER_ANY,
			QUANTIFIER_MAYBE,
			QUANTIFIER_SEVERAL,
			ALTERNATION,
			CONCATENATION,
			END
		};
		Type				type;
		std::bitset<128>	included;
		int					left;
		int					right;
		Node(Type type, int left, int right);
	};
	AST(Lexer &lexer);
	int		getRoot(void) const;
	int		getEnd(void) const;
	int		size(void) const;
	Node	&operator[](int id);
	Node const	&operator[](int id) const;
private:
	int root;
	int	end;
	std::vector<Node>	nodes;
	int	createNode(Node::Type type, int left, int right);
	int	parseExpr(Lexer &lexer, int prefix_pull);
	int	parseClass(Lexer &lexer);
};

#endif
