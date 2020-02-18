#ifndef PROBLEM_H
#define PROBLEM_H

#include "tree.h"


class Problem {
   private:
	Tree* initial_state;
	Tree* curr_state;
	Tree* goal_state;
   public:
	Problem();
	Problem(Tree* custom);
	bool moveUp(int);
	bool moveDown(int);
	bool moveLeft(int);
	bool moveRight(int);
	Tree* getGoal();
	Tree* getCurr();
	bool isGoal(Tree*);
};

#endif
