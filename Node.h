#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node
{
public:
	vector<vector<int>> state;
	int cost = 0;
	int index = 0;
	int depth = 0;
	Node();

	Node(vector<vector<int>> newState, int c, int i);
	Node(vector<vector<int>> newState, int c, int i, int d);
};

struct Compare : public binary_function<Node*, Node*, bool>
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return lhs->cost > rhs->cost;
	}
};


#endif