#include "problem.h"

Problem::Problem(){
	 vector<vector<int>> temp { { 0, 1, 2},
                                    { 3, 4, 5},
                                    { 6, 7, 8}}; //right,down,up,left
 	 vector<vector<int>> end { { 1, 2, 3},
                                   { 4, 5, 6},
                                   { 7, 8, 0}}; //right,down,up,left
	this->initial_state = new Tree(temp);
	this->goal_state = new Tree(end);
	this->curr_state = this->inital_state;
}

Problem::Problem(Tree* custom){
	this->inital_state = custom;
	 vector<vector<int>> end { { 1, 2, 3},
                                   { 4, 5, 6},
                                   { 7, 8, 0}}; //right,down,up,left
	 this->goal_state = new Tree(end);
	 curr_state = initial_state;
}


bool Problem::moveUp(int i){
	if(i = 0 || i = 1 || i = 2){
		return false;
	}
	return true;
}
	
bool Problem::moveDown(int i){
	if(i = 6 || i = 7 || i = 8){
		return false;
	}
	return true;
}
bool Problem::moveLeft(int i){
	if(i = 0 || i = 3 || i = 6){
		return false;
	}
	return true;
}
bool Problem::moveRight(int i){
	if(i = 2 || i = 5 || i = 8){
		return false;
	}
	return true;
}

Tree* Problem::getGoal(){
	return this->goal_state;
}

Tree* Problem::getCurr(){
	return this->curr_state;
}
bool Problem::isGoal(Tree* node){
	if(node->getState == this->curr_state){
		return true;
	}
	return false;
} 
