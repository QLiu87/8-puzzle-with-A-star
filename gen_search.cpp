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
				misplaced++;

			}
		}
	}
	return misplaced;
}

int solve(vector<vector<int>> initial, int choice)
{
	int indexCounter = -1;
	int blank_position = 0;
	int size = 3;

	vector<vector<int> > goal{{ 1, 2, 3 },
							 { 4, 5, 6 },
							 { 7, 8, 0 }}; //right,down,up,left

	vector<Node*> explored;
	vector<Node*> visited;

	Node* root = new Node();
	root->state = initial;
	root->cost = 0;
	root->depth = 0;
	priority_queue<Node*, vector<Node*>, Compare> frontier;
	frontier.push(root);
	visited.push_back(root);
	Node *temp = frontier.top();

	// finding the position of zero
	for (std::size_t i = 0; i < initial.size(); i++)
	{
		for (std::size_t j = 0; j < initial[0].size(); j++)
		{
			if (initial.at(i).at(j) > 0)
			{
				if (indexCounter == -1)
				{
					blank_position++;
				}
			}
			else if (initial.at(i).at(j) == 0)
			{
				indexCounter = blank_position;
			}
		}
	}

	int n = 0;
	int index = indexCounter;
	cout << "Expanding state" << endl;

	// print out the current state
	for (std::size_t i = 0; i < temp->state.size(); i++)
	{
		for (std::size_t j = 0; j < temp->state[0].size(); j++)
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

		//return solution
		if (temp->state == goal)
		{
			cout << "Goal!!!!!!!!!!" << endl;
			cout << endl;
			//cout << "The total number " << visited.size() << endl;
			cout << "To solve this problem the search algorithm expanded a total of " << explored.size()
				<< " nodes." << endl;
			cout << "The maximum number of nodes in the queue at any one time was " << frontier.size() << "." << endl;
			cout << "The depth of the goal node was " << temp->depth << "." << endl;
			return 1;
		}

		// add Node.state to explored
		explored.push_back(temp);

		//print the expansion state
		if (n != 0)
		{
			cout << "The best state to expand with a g(n) = " << frontier.top()->depth << " and h(n) = " << frontier.top()->cost - frontier.top()->depth
				<< " is..." << endl;
			for (std::size_t i = 0; i < frontier.top()->state.size(); i++)
			{
				for (std::size_t j = 0; j < frontier.top()->state[0].size(); j++)
				{
					cout << frontier.top()->state.at(i).at(j) << " ";
				}
				cout << endl;
			}
		}

		frontier.pop();

		//actions
		if (moveRight(index, size)) //move right
		{
			new_index = index + 1;
			vector<vector<int> > tempState = temp->state;
			int x, row, tempNum, tempCost, tempDepth,h_n;
			getCoordinate(new_index, x, row);
			cout << "x = " << x << endl << "row = " << row << endl;
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

			bool newChildState = false;
			for (std::size_t i = 0; i < visited.size(); i++)
			{
				if (tempState == visited.at(i)->state)
				{
					newChildState = true;
				}
			}
			//not in the frontier or explored set
			if (!newChildState)
			{
				Node* child = new Node(tempState, tempCost, new_index, tempDepth);
				frontier.push(child);
				visited.push_back(child);
			}

		}

		if (moveDown(index, size))//move down
		{
			new_index = index + size;
			vector<vector<int> > tempState = temp->state;
			int x, row, tempNum, tempCost, tempDepth,h_n;
			getCoordinate(new_index, x, row);
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

			bool newChildState = false;
			for (std::size_t i = 0; i < visited.size(); i++)
			{
				if (tempState == visited.at(i)->state)
				{
					newChildState = true;
				}
			}
			//not in the frontier or explored set
			if (!newChildState)
			{
				Node* child = new Node(tempState, tempCost, new_index, tempDepth);
				frontier.push(child);
				visited.push_back(child);
			}

		}

		if (moveUp(index, size))//move up
		{
			new_index = index - size;
			vector<vector<int> >  tempState = temp->state;
			int x, row, tempNum, tempCost, tempDepth, h_n;
			getCoordinate(new_index, x, row);
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


			bool newChildState = false;
			for (std::size_t i = 0; i < visited.size(); i++)
			{
				if (tempState == visited.at(i)->state)
				{
					newChildState = true;
				}
			}
			//not in the frontier or explored set
			if (!newChildState)
			{
				Node* child = new Node(tempState, tempCost, new_index, tempDepth);
				frontier.push(child);
				visited.push_back(child);
			}

		}

		if (moveLeft(index, size))//move left
		{
			new_index = index - 1;
			vector<vector<int> > tempState = temp->state;
			int x, row, tempNum, tempCost, tempDepth,h_n;
			getCoordinate(new_index, x, row);
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

			bool newChildState = false;
			for (std::size_t i = 0; i < visited.size(); i++)
			{
				if (tempState == visited.at(i)->state)
				{
					newChildState = true;
				}
			}
			//not in the frontier or explored set
			if (!newChildState)
			{
				Node* child = new Node(tempState, tempCost, new_index, tempDepth);
				frontier.push(child);
				visited.push_back(child);
			}

		}

		cout << endl;

		index = frontier.top()->index;
		n++;

	}


}
