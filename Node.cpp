#include "Node.h"

Node::Node()
{

}

Node::Node(vector<vector<int> > newState, int c, int i)
{
	state = newState;
	cost = c;
	index = i;
}

Node::Node(vector<vector<int> > newState, int c, int i, int d)
{
	state = newState;
	cost = c;
	index = i;
	depth = d;
}


