fndef TREE_H
#define TREE_H
#include "headers.h"
class Tree{
    private:
	vector<vector<int>> state;
	int cost;
	int index;
    public:
	Tree();
	Tree(vector<vector<int>> problem, int c = 0, int i = 0);
	int getIndex();
	int getCost();
	vector<vector<int>> getState();
	void setIndex(int i);
	void setCost(int c);
	vector<vector<int>> getState();
	void setState(<vector<vector<int>> problem);
};



#endif
