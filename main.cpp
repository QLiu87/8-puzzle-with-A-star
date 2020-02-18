#include "main.h"
int main()
{
    int option, size;
    vector<vector<int>> start;
                                
    cout << "Welcome to 861231381's 8-puzzle solver." << endl;
    cout << "Type '1' to use a default puzzle and '2' to enter your own puzzle" << endl;
    cin >> option;
    if(option == 1)
    {
        vector<vector<int>> temp { { 0, 1, 2 },
                                { 4, 8,3 },
                                {7,6, 5}}; //right,down,up,left
        start = temp;
        size = 3;
    }
	else if (option == 2)
	{
		cout << "Enter your puzzle, use a zero to represent the blank " << endl;
		cout << "Enter the first row, use space between numbers ";
		int input1, input2, input3;
		cin >> input1 >> input2 >> input3;
		vector<int> input; //rows
		input.push_back(input1);
		input.push_back(input2);
		input.push_back(input3);
		start.push_back(input);
		input.clear();

		cout << "Enter the second row, use space between numbers ";
		cin >> input1 >> input2 >> input3;
		input.push_back(input1);
		input.push_back(input2);
		input.push_back(input3);
		start.push_back(input);
		input.clear();

		cout << "Enter the third row, use space between numbers ";
		cin >> input1 >> input2 >> input3;
		input.push_back(input1);
		input.push_back(input2);
		input.push_back(input3);
		start.push_back(input);
		input.clear();
	}
	cout << "Enter your choice of algorithm" << endl;
	cout << "1. Uniform Cost Search" << endl;
	cout << "2. A* with the Misplaced Tile heuristic" << endl;
	cout << "3. A* with the Manhattan distance heuristic" << endl;
	int searchNum = 0;
	cin >> searchNum;
	size = 3;
	general_search(start,searchNum);

    return 0;
}
