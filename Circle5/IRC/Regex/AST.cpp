
#include "AST.hpp"
#include <stdexcept>

AST::Node::Node(Type type, int left, int right) {
	this->type = type;
	this->left = left;
	this->right = right;
}
AST::AST(Lexer &lexer) {
	int const	root = this->parseExpr(lexer, 0);
	int const	terminator = this->createNode(Node::END, -1, -1);
	this->root = this->createNode(Node::CONCATENATION, root, terminator);
	this->end = terminator;
}

AST::Node	&AST::operator[](int id) {
	return (this->nodes[id]);
}

AST::Node const	&AST::operator[](int id) const {
	return (this->nodes[id]);
}


int	AST::getRoot(void) const {
	return (this->root);
}

int	AST::getEnd(void) const {
	return (this->end);
}

int	AST::size(void) const {
	return (this->nodes.size());
}

int	AST::createNode(Node::Type type, int left, int right) {
	int const	id = this->nodes.size();
	this->nodes.push_back(Node(type, left, right));

	return (id);
}

/*
+?*
| .
()

concat 3, 4
alter 1, 2
quant 5, *

*/
int	AST::parseExpr(Lexer &lexer, int prefix_pull) {
	Token	token = lexer.next();
	int		lhs;

	switch (token.type)
	{
	case Token::CHARACTER:
		lhs = this->createNode(Node::LEAF, -1, -1);
		this->nodes[lhs].included[token.symbol] = true;
		break;
	case Token::LPAREN:
		lhs = this->parseExpr(lexer, 0);
		if (lexer.next().type != Token::RPAREN)
			throw std::runtime_error("Error paren");
		break;
	case Token::LBRACKET:
		lhs = this->parseClass(lexer);
		if (lexer.next().type != Token::RBRACKET)
			throw std::runtime_error("Error bracket");
		break;
	default:
		throw std::runtime_error("Unexpected token");
	}
	while (1) {
		Token	next = lexer.peek();
		std::pair<int, int>	pull;

		if (next.type == Token::QUANTIFIER) {
			if (5 < prefix_pull) // lhs_pull(quantifier)
				break ;
			lexer.next();
			switch (next.symbol)
			{
			case '*':
				lhs = this->createNode(Node::QUANTIFIER_ANY, lhs, -1);
				break;
			case '?':
				lhs = this->createNode(Node::QUANTIFIER_MAYBE, lhs, -1);
				break;
			case '+':
				lhs = this->createNode(Node::QUANTIFIER_SEVERAL, lhs, -1);
				break;
			default:
				throw std::runtime_error("ERROR");
			}
		} else if (next.type == Token::CHARACTER || next.type == Token::LPAREN || next.type == Token::LBRACKET) {
			if (3 < prefix_pull) // lhs_pull(concat)
				break ;
			int rhs = this->parseExpr(lexer, 4);
			lhs = this->createNode(Node::CONCATENATION, lhs, rhs);
		} else if (next.type == Token::ALTERNATION) {
			if (1 < prefix_pull) // lhs_pull(alternation)
				break ;
			lexer.next();
			int rhs = this->parseExpr(lexer, 2);
			lhs = this->createNode(Node::ALTERNATION, lhs, rhs);
		} else {
			break ;
		}
	}
	return (lhs);
}

int	AST::parseClass(Lexer &lexer) {
	int	node_id = this->createNode(Node::LEAF, -1, -1);
	Node	&node = this->nodes[node_id];
	bool	inverted = false;

	if (lexer.peek().type == Token::CARET) {
		inverted = true;
		lexer.next();
	}
	while(1) {
		Token	token = lexer.peek();
		switch (token.type)
		{
		case Token::RBRACKET:
			if (inverted)
				node.included.flip();
			return (node_id);
		case Token::CHARACTER:
			lexer.next();
			if (lexer.peek().type == Token::RANGE) {
				Token rhs = (lexer.next(), lexer.peek());
				if (rhs.type != Token::CHARACTER)
					throw std::runtime_error("Bad character class0");
				lexer.next();
				for (int c = token.symbol; c <= rhs.symbol; c++)
					node.included[c] = true;
			} else if (lexer.peek().type == Token::CHARACTER) {
				lexer.next();
				node.included[token.symbol] = true;
			} else if ( lexer.peek().type == Token::RBRACKET) {
				node.included[token.symbol] = true;
			} else
				throw std::runtime_error("Bad character class1");
			break;
		default:
			throw std::runtime_error("Bad character class2");
		}
	}
	throw std::runtime_error("how?");
}
