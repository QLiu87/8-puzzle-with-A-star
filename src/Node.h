#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <cstdlib>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node
{
private:
	Node* parent;
public:

	vector< vector<int> > state;
	int cost = 0;
	int index = 0;
	int depth = 0;
	Node();
	Node* getParent();
	void setParent(Node*);
	Node(vector<vector<int> > newState, int c, int i);
	Node(vector<vector<int> > newState, int c, int i, int d, Node* p = 0);
};

struct Compare : public binary_function<Node*, Node*, bool>
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return lhs->cost > rhs->cost;
	}
};


#endif
