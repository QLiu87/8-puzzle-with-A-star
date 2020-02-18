#include "gen_search.h"
int mht_distance(vector<vector<int> > state, vector<vector<int> > goal)
{
	int moves = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (state.at(i).at(j) != goal.at(i).at(j))
			{
				if (state.at(i).at(j) == 1)
				{
					moves = moves + abs(i - 0) + abs(j - 0);
				}
				else if (state.at(i).at(j) == 2)
				{
					moves = moves + abs(i - 0) + abs(j - 1);
				}
				else if (state.at(i).at(j) == 3)
				{
					moves = moves + abs(i - 0) + abs(j - 2);
				}
				else if (state.at(i).at(j) == 4)
				{
					moves = moves + abs(i - 1) + abs(j - 0);
				}
				else if (state.at(i).at(j) == 5)
				{
					moves = moves + abs(i - 1) + abs(j - 1);
				}
				else if (state.at(i).at(j) == 6)
				{
					moves = moves + abs(i - 1) + abs(j - 2);
				}
				else if (state.at(i).at(j) == 7)
				{
					moves = moves + abs(i - 2) + abs(j - 0);
				}
				else if (state.at(i).at(j) == 8)
				{
					moves = moves + abs(i - 2) + abs(j - 1);
				}
			}
		}
	}
	return moves;
}
int numofMisplaced(vector<vector<int> > state, vector<vector<int> > goal)
{
	int misplaced = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (state.at(i).at(j) != goal.at(i).at(j))
			{
				misplaced = misplaced + 1;

			}
		}
	}
	return misplaced;
}

int general_search(vector<vector<int>> initial, int choice)
{
	int indexRoot = -1;
	int blank_position = 0;
	int size = 3;
	//int startNum = 1;
	vector<vector<int> > goal{{ 1, 2, 3 },
							 { 4, 5, 6 },
							 { 7, 8, 0 }}; //right,down,up,left

	/*
	goal.resize(3, vector<int>(size, 0));
	for (int i = 0; i < goal.size(); i++)
	{
		for (int j = 0; j < goal[0].size(); j++)
		{
			goal.at(i).at(j) = startNum;
			startNum++;
		}
	}
	goal.at(goal.size() - 1).at(goal.size() - 1) = 0;
	*/
	vector<Node*> explored;
	vector<Node*> frontierCheck;

	Node* root = new Node();
	root->state = initial;
	root->cost = 0;
	root->depth = 0;
	priority_queue<Node*, vector<Node*>, Compare> frontier;
	frontier.push(root);
	frontierCheck.push_back(root);
	Node *temp = frontier.top();

	// finding the position of zero
	for (int i = 0; i < initial.size(); i++)
	{
		for (int j = 0; j < initial[0].size(); j++)
		{
			if (initial.at(i).at(j) > 0)
			{
				if (indexRoot == -1)
				{
					blank_position++;
				}
			}
			else if (initial.at(i).at(j) == 0)
			{
				indexRoot = blank_position;
			}
		}
	}

	int n = 0;
	int index = indexRoot;
	cout << "Expanding state" << endl;

	// print out the current state
	for (int i = 0; i < temp->state.size(); i++)
	{
		for (int j = 0; j < temp->state[0].size(); j++)
		{
			cout << temp->state.at(i).at(j) << " ";
		}
		cout << endl;
	}

	while (true)
	{
		int new_index;
		Node* temp = frontier.top();
		//when frontier is empty, return failure
		if (frontier.size() == 0)
		{
			cout << "NO solution" << endl;
			exit(0);
		}
		if (temp->state == goal)
		{
			cout << "Goal!!!!!!!!!!" << endl;
			cout << endl;
			//cout << "The total number " << frontierCheck.size() << endl;
			cout << "To solve this problem the search algorithm expanded a total of " << explored.size()
				<< " nodes." << endl;
			cout << "The maximum number of nodes in the queue at any one time was " << frontier.size() << "." << endl;
			cout << "The depth of the goal node was " << temp->depth << "." << endl;
			return 1;
		}
		explored.push_back(temp);

		if (n != 0)
		{
			cout << "The best state to expand with a g(n) = " << frontier.top()->depth << " and h(n) = " << frontier.top()->cost - frontier.top()->depth
				<< " is..." << endl;
			for (int i = 0; i < frontier.top()->state.size(); i++)
			{
				for (int j = 0; j < frontier.top()->state[0].size(); j++)
				{
					cout << frontier.top()->state.at(i).at(j) << " ";
				}
				cout << endl;
			}
		}

		frontier.pop();

		if (moveRight(index, size)) //move right
		{
			new_index = index + 1;
			vector<vector<int> > tempState = temp->state;
			int x, row, tempNum, tempCost, tempDepth,h_n;
			cout << new_index << endl;
			checkXY(new_index, x, row);

			//swap two index
			tempNum = temp->state.at(row).at(x);
			tempState.at(row).at(x - 1) = tempNum;
			tempState.at(row).at(x) = 0;

			//cost depends on choice
			tempDepth = temp->depth + 1;
			if (choice == 1) {
				h_n = 1;
			}
			else if (choice == 2) {
				h_n = numofMisplaced(tempState, goal);
			}
			else if (choice == 3) {
				h_n = mht_distance(tempState, goal);
			}
			tempCost = tempDepth + h_n;

			int numRe = 0;
			for (int i = 0; i < frontierCheck.size(); i++)
			{
				if (tempState != frontierCheck.at(i)->state)
				{
					numRe++;
				}
			}
			//not in the frontier or explored set
			if (numRe == (frontierCheck.size()))
			{
				Node* child = new Node(tempState, tempCost, new_index, tempDepth);
				frontier.push(child);
				frontierCheck.push_back(child);
			}

		}

		if (moveDown(index, size))//move down
		{
			new_index = index + size;
			vector<vector<int> > tempState = temp->state;
			int x, row, tempNum, tempCost, tempDepth,h_n;
			checkXY(new_index, x, row);
			tempNum = temp->state.at(row).at(x);
			tempState.at(row - 1).at(x) = tempNum;
			tempState.at(row).at(x) = 0;
			tempDepth = temp->depth + 1;
			if (choice == 1) {
				h_n = 1;
			}
			else if (choice == 2) {
				h_n = numofMisplaced(tempState, goal);
			}
			else if (choice == 3) {
				h_n = mht_distance(tempState, goal);
			}
			tempCost = tempDepth + h_n;
			int numRe = 0;
			for (int i = 0; i < frontierCheck.size(); i++)
			{
				if (tempState != frontierCheck.at(i)->state)
				{
					numRe++;
				}
			}
			if (numRe == (frontierCheck.size()))
			{
				Node* child = new Node(tempState, tempCost, new_index, tempDepth);
				frontier.push(child);
				frontierCheck.push_back(child);
			}

		}

		if (moveUp(index, size))//move up
		{
			new_index = index - size;
			vector<vector<int> >  tempState = temp->state;
			int x, row, tempNum, tempCost, tempDepth, h_n;
			checkXY(new_index, x, row);
			tempNum = temp->state.at(row).at(x);
			tempState.at(row + 1).at(x) = tempNum;
			tempState.at(row).at(x) = 0;
			tempDepth = temp->depth + 1;
			if (choice == 1) {
				h_n = 1;
			}
			else if (choice == 2) {
				h_n = numofMisplaced(tempState, goal);
			}
			else if (choice == 3) {
				h_n = mht_distance(tempState, goal);
			}
			tempCost = tempDepth + h_n;
			int numRe = 0;
			for (int i = 0; i < frontierCheck.size(); i++)
			{
				if (tempState != frontierCheck.at(i)->state)
				{
					numRe++;
				}
			}
			if (numRe == (frontierCheck.size()))
			{
				Node* child = new Node(tempState, tempCost, new_index, tempDepth);
				frontier.push(child);
				frontierCheck.push_back(child);
			}


		}

		if (moveLeft(index, size))//move left
		{
			new_index = index - 1;
			vector<vector<int> > tempState = temp->state;
			int x, row, tempNum, tempCost, tempDepth,h_n;
			checkXY(new_index, x, row);
			tempNum = temp->state.at(row).at(x);
			tempState.at(row).at(x + 1) = tempNum;
			tempState.at(row).at(x) = 0;
			tempDepth = temp->depth + 1;
			if (choice == 1) {
				h_n = 1;
			}
			else if (choice == 2) {
				h_n = numofMisplaced(tempState, goal);
			}
			else if (choice == 3) {
				h_n = mht_distance(tempState, goal);
			}
			tempCost = tempDepth + h_n;
			int not_visited = 0;
			for (int i = 0; i < frontierCheck.size(); i++)
			{
				if (tempState != frontierCheck.at(i)->state)
				{
					not_visited++;
				}
			}
			if (not_visited == (frontierCheck.size()))
			{
				Node* child = new Node(tempState, tempCost, new_index, tempDepth);
				frontier.push(child);
				frontierCheck.push_back(child);
			}

		}

		cout << endl;

		index = frontier.top()->index;
		n++;

	}


}
