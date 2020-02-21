#include "Node.h"

Node::Node()
{

}

Node::Node(vector<vector<int> > newState, int c, int i)
{
	state = newState;
	cost = c;
	index = i;
	parent = 0;
}

Node::Node(vector<vector<int> > newState, int c, int i, int d, Node* p)
{
	state = newState;
	cost = c;
	index = i;
	depth = d;
	parent = p;
}

Node* Node::getParent() {
	return this->parent;
}
void Node::setParent(Node* n) {
	this->parent = n;
}
