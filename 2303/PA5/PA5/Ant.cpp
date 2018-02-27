/*
 * Ant.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "Ant.h"

/**
 * Constructor with just x and y coordinates
 * @param x The x coordinate of the Ant
 * @param y The y coordinate of the Ant
 * @return void does not return anything
 */
Ant::Ant(int x,int y) : Organism(true,x,y) {
	//Calls the super class with true (it is prey), and then its respective x and y coordinates
}

/**
 * Constructor with x/y coordinates and a boolean representing if it has moved or not
 * @param x The x coordinate of the Ant
 * @param y The y coordinate of the Ant
 * @param hasMoved Boolean representing if the organism has moved or not
 */
Ant::Ant(int x,int y,bool hasMoved) : Organism(true,x,y,hasMoved) {
	//Calls the parent class making it prey and passing the rest of the given parameters
}

/**
 * Ants cannot be starved, but they must implement the method
 * @return 0 Returns null because an Ant cannot starve
 */
bool Ant::isItStarved(){
	//Returns 0 (null)
	return 0;
}

/**
 * Gives back an int representing where the Ant should move to
 * @param n1 Neighbor 1, an int representing what type is above the Ant
 * 0 means empty, 1 means Doodlebug, 2 means Ant, 3 means off grid
 * @param n2 Neighbor 2 (right)
 * @param n3 Neighbor 3 (below)
 * @param n4 Neighbor 4 (right)
 * @return Returns 0 to go nowhere, 1 up, 2 right, 3 down, 4 left
 */
int Ant::move(int n1,int n2,int n3,int n4){

	//Now that it is moving, make hasMoved true
	this->setHasMoved(true);
	//Increment the number of taken steps
	this->incrStep();

	//If the Ant has taken three steps it is eligible to breed (reset of steps happens in board)
	if(this->getSteps()==3){this->switchElgBreed();}

	//Ants only need to move to an empty spot, no other priority

	//Cases where one space is available to move to
	if(n1==0&&n2!=0&&n3!=0&&n4!=0){return 1;}
	if(n1!=0&&n2==0&&n3!=0&&n4!=0){return 2;}
	if(n1!=0&&n2!=0&&n3==0&&n4!=0){return 3;}
	if(n1!=0&&n2!=0&&n3!=0&&n4==0){return 4;}

	//Cases where two spaces are available to move to

	//1 and 2 are available
	if(n1==0&&n2==0&&n3!=0&&n4!=0){
		int r = rand()%(2)+1;
		return r;
	}

	//3 and 4
	if(n1!=0&&n2!=0&&n3==0&&n4==0){
		int r = rand()%(2)+3;
		return r;
	}

	//1 and 3
	if(n1==0&&n2!=0&&n3==0&&n4!=0){
		int r = rand()%(2)+1;
		if(r==2){return 3;}
		return r;
	}

	//1 and 4
	if(n1==0&&n2!=0&&n3!=0&&n4==0){
		int r = rand()%(2)+1;
		if(r==2){return 4;}
		return r;
	}

	//2 and 3
	if(n1!=0&&n2==0&&n3==0&&n4!=0){
		int r = rand()%(2)+2;
		return r;
	}

	//2 and 4
	if(n1!=0&&n2==0&&n3!=0&&n4==0){
		int r = rand()%(2)+1;
		if(r==1){return 4;}
		return r;
	}

	//Cases when there are three available spaces

	//1,2,3
	if(n1==0&&n2==0&&n3==0&&n4!=0){
		int r = rand()%(3)+1;
		return r;
	}

	//2,3,4
	if(n1!=0&&n2==0&&n3==0&&n4==0){
		int r = rand()%(3)+2;
		return r;
	}

	//3,4,1
	if(n1==0&&n2!=0&&n3==0&&n4==0){
		int r = rand()%(3)+2;
		if(r==2){return 1;}
		return r;
	}

	//1,2,4
	if(n1==0&&n2==0&&n3!=0&&n4==0){
		int r = rand()%(3);
		if(r==0){return 4;}
		return r;
	}

	//Case if all spaces are available
	if(n1==0&&n2==0&&n3==0&&n4==0){
		int r = rand()%(4)+1;
		return r;
	}

	//If all else fails, stay put
	return 0;

}

/**
 * Returns where the Ant should breed.
 * @param n1 Neighbor 1, an int representing what type is above the Ant
 * 0 means empty, 1 means Doodlebug, 2 means Ant, 3 means off grid
 * @param n2 Neighbor 2 (right)
 * @param n3 Neighbor 3 (below)
 * @param n4 Neighbor 4 (right)
 * @return Returns 0 to go nowhere, 1 up, 2 right, 3 down, 4 left
 */
int Ant::whereToBreed(int n1,int n2,int n3,int n4){
	//Because all an Ant needs is an empty space, it can call move which give back an empty
	//space for where it can put the new Ant
	return move(n1,n2,n3,n4);
}

/**
 * Destructor
 * @return void Does not return anything
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

