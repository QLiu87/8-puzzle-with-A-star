#include "tree.h"

Tree::Tree(){
	this->cost = 0;
	this->index = 0;
	this->state = null;
}

Tree::Tree(vector<vector<int>> problem, int c =0, int i = 0){
	this->state = problem;
	cost = c;
	index = i;
}

int Tree::getIndex(){
	if(this->index >8 || this->index <0){
		return -1;
	}
	else{
		return this->index;
	}
}

int Tree::getCost(){
	return this->cost;
}

vector<vector<int>> Tree::getState(){
	return this->state;
}

void Tree::setIndex(int i){
	this->index = i;
}

void Tree::setCost(int c){
	this->cost = c;
}


