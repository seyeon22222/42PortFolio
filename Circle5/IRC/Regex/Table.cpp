
#include "Table.hpp"
#include <stdexcept>

Table::Table(AST const &ast) {
	this->computeNullable(ast);
	this->computeFirst(ast);
	this->computeLast(ast);
	this->computeFollow(ast);
}

void	Table::computeNullable(AST const &ast) {
	for (int i = 0; i < ast.size(); i++) {
		AST::Node const	&node = ast[i];
	
		switch (node.type)
		{
		case AST::Node::END:
			this->nullable.push_back(true);
			break;
		case AST::Node::LEAF:
			this->nullable.push_back(false);
			break ;
		case AST::Node::ALTERNATION:
		this->nullable.push_back(this->nullable[node.left] || this->nullable[node.right]);
			break ;
		case AST::Node::CONCATENATION:
			this->nullable.push_back(this->nullable[node.left] && this->nullable[node.right]);
			break;
		case AST::Node::QUANTIFIER_ANY:
		case AST::Node::QUANTIFIER_MAYBE:
			this->nullable.push_back(true);
			break ;
		case AST::Node::QUANTIFIER_SEVERAL:
			this->nullable.push_back(this->nullable[node.left]);
			break ;
		default:
			throw std::runtime_error("Bad node");
		}
	}
}


void	Table::computeFirst(AST const &ast) {
	for (int i = 0; i < ast.size(); i++) {
		AST::Node const	&node = ast[i];
		std::set<int>	set;

		switch (node.type)
		{
		case AST::Node::END:
		case AST::Node::LEAF:
			set.insert(i);
			break ;
		case AST::Node::ALTERNATION:
			set.insert(this->first[node.left].begin(), this->first[node.left].end());
			set.insert(this->first[node.right].begin(), this->first[node.right].end());
			break;
		case AST::Node::CONCATENATION:
			set.insert(this->first[node.left].begin(), this->first[node.left].end());
			if (this->nullable[node.left]) {
				set.insert(this->first[node.right].begin(), this->first[node.right].end());
			}
			break;
		case AST::Node::QUANTIFIER_ANY:
		case AST::Node::QUANTIFIER_MAYBE:
		case AST::Node::QUANTIFIER_SEVERAL:
			set.insert(this->first[node.left].begin(), this->first[node.left].end());
			break;
		default:
			throw std::runtime_error("Bad node");
		}
		this->first.push_back(set);
	}
}

void	Table::computeLast(AST const &ast) {
	for (int i = 0; i < ast.size(); i++) {
		AST::Node const	&node = ast[i];
		std::set<int>	set;

		switch (node.type)
		{
		case AST::Node::END:
		case AST::Node::LEAF:
			set.insert(i);
			break ;
		case AST::Node::ALTERNATION:
			set.insert(this->last[node.left].begin(), this->last[node.left].end());
			set.insert(this->last[node.right].begin(), this->last[node.right].end());
			break;
		case AST::Node::CONCATENATION:
			set.insert(this->last[node.right].begin(), this->last[node.right].end());
			if (this->nullable[node.right]) {
				set.insert(this->last[node.left].begin(), this->last[node.left].end());
			}
			break;
		case AST::Node::QUANTIFIER_ANY:
		case AST::Node::QUANTIFIER_MAYBE:
		case AST::Node::QUANTIFIER_SEVERAL:
			set.insert(this->last[node.left].begin(), this->last[node.left].end());
			break;
		default:
			throw std::runtime_error("Bad node");
		}
		this->last.push_back(set);
	}
}
#include <iostream>
void	Table::computeFollow(AST const &ast) {
	for (int i = 0; i < ast.size(); i++) {
		AST::Node const	&node = ast[i];
		std::set<int>	set;

		switch (node.type)
		{
		case AST::Node::CONCATENATION:
			{
				std::set<int>	&f2 = this->first[node.right];
				std::set<int>	&l1 = this->last[node.left];
				for (std::set<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
					this->follow[*it].insert(f2.begin(), f2.end());
				}
			}
			break;
		case AST::Node::QUANTIFIER_ANY:
		case AST::Node::QUANTIFIER_SEVERAL:
			{
				std::set<int>	&f1 = this->first[node.left];
				std::set<int>	&l1 = this->last[node.left];
				for (std::set<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
					this->follow[*it].insert(f1.begin(), f1.end());
				}
			}
			break;
		default:
			break ;
		}
		// this->last.push_back(set);
	}
}

