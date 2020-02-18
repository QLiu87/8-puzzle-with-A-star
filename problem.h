#ifndef PROBLEM_H
#define PROBLEM_H

#include "tree.h"


class Problem {
   private:
	Tree* inital_state;
	Tree* curr_state;
	Tree* goal_state;
   public:
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
	Tree* getGoal();
	Tree* getCurr();
};

#endif
