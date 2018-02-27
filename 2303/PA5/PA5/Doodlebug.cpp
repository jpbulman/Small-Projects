/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "Doodlebug.h"

/**
 * Constructor for Doodlebug
 * @param x The x coordinate
 * @param y The y coordinate
 * @return Does not return anything
 */
Doodlebug::Doodlebug(int x,int y) : Organism(false,x,y) {
	//Calls the super class (Organism) constructor making it not prey, and giving it the passed
	//in x and y coords

	//Is not starved by default
	isStarved=false;
	//Has not taken any steps at all yet
	stepsWithoutEating=0;
}

/**
 * Overloaded constructor for Doodlebug with a hasMoved boolean
 * @param x The x coordinate
 * @param y The y coordinate
 * @param hasMoved A boolean saying if the organism has moved already or not
 * @return Does not return anything
 */
Doodlebug::Doodlebug(int x,int y,bool hasMoved) : Organism(false,x,y,hasMoved) {
	//Calls the super class (Organism) constructor making it not prey, giving it the passed
	//in x and y coords, and giving it the passed hasMoved boolean

	//Is not starved by default
	isStarved=false;
	//Has not taken any steps at all yet
	stepsWithoutEating=0;
}

/**
 * Determines if the Doodlebug has starved
 * @return isStarved Returns if the db has starved or not
 */
bool Doodlebug::isItStarved(){
	//Returns the field representing if the db has staved or not
	return isStarved;
}

/**
 * Determines where to move the doodle bug
 * @param n1 Neighbor 1 (above), 0 means empty, 1 means Doodlebug, 2 means Ant, 3 means off grid
 * @param n1 Neighbor 2 (right), 0-empty, 1-Doodlebug, 2-Ant, 3-off grid
 * @param n1 Neighbor 3 (below), 0-empty, 1-Doodlebug, 2-Ant, 3-off grid
 * @param n1 Neighbor 4 (left), 0-empty, 1-Doodlebug, 2-Ant, 3-off grid
 * @return Returns 0 to go nowhere, 1 up, 2 right, 3 down, 4 left
 */
int Doodlebug::move(int n1,int n2,int n3,int n4){

	//The db is now moving, so therefore has moved
	this->setHasMoved(true);
	//Has taken one more step
	this->incrStep();
	//Has taken another step without eating
	stepsWithoutEating++;

	//If it has reached 8 steps, it is now eligible to breed
	if(this->getSteps()==8){this->switchElgBreed();}
	//If it has taken 3 steps without eating an ant, it starves
	if(stepsWithoutEating==3){isStarved=true;}

	//If above is an ant and the other spaces are not
	if(n1==2&&n2!=2&&n3!=2&&n4!=2){stepsWithoutEating=0;return 1;}

	//If right is an ant and the other spaces are not
	if(n1!=2&&n2==2&&n3!=2&&n4!=2){stepsWithoutEating=0;return 2;}

	//If below is an ant and the other spaces are not
	if(n1!=2&&n2!=2&&n3==2&&n4!=2){stepsWithoutEating=0;return 3;}

	//If left is an ant and the other spaces are not
	if(n1!=2&&n2!=2&&n3!=2&&n4==2){stepsWithoutEating=0;return 4;}


	//If every neighbor is a Doodlebug, then do not move (just know you're about to die)
	if(n1==1&&n2==1&&n3==1&&n4==1){return 0;}


	//If every neighbor is an ant or if every space is blank
	if((n1==2&&n2==2&&n3==2&&n4==2)||(n1==0&&n2==0&&n3==0&&n4==0)){

		//If they are ants, then the db will eat
		if(n1==2&&n2==2&&n3==2&&n4==2){stepsWithoutEating=0;}

		//Generates a random number [1,4]
		int r = rand()%(4)+1;

		return r;
	}

	//Cases if three neighbors are ants

	//n1,n2, and n3 are ants, n4 is not
	if(n1==2&&n2==2&&n3==2&&n4!=2){

		//The db will be eating, so steps reset
		stepsWithoutEating=0;

		//Random number [1,3]
		int r = rand()%(3)+1;

		return r;
	}
	//n2,n3, and n4 are ants, n1 is not
	if(n1!=2&&n2==2&&n3==2&&n4==2){

		stepsWithoutEating=0;

		//Random number [2,4]
		int r = rand()%(3)+2;

		return r;
	}
	//n1,n3, and n4 are ants, n2 is not
	if(n1==2&&n2!=2&&n3==2&&n4==2){

		stepsWithoutEating=0;

		//Random number [3,5]
		int r = rand()%(3)+3;

		//If the number is 5 (there is not a direction for that), return 1
		if(r==5){return 1;}

		return r;
	}
	//n1,n2, and n4 are ants, n3 is not
	if(n1==2&&n2==2&&n3!=2&&n4==2){

		stepsWithoutEating=0;

		//Random number [1,3]
		int r = rand()%(3)+1;

		//Need to return 1,2, or 4, number is 1->3, so if it is 4, just return 3
		if(r==3){return 4;}

		return r;
	}


	//Cases if two spaces have ants

	//n1 and n2 are ants, n3 and n4 are not
	if(n1==2&&n2==2&&n3!=2&&n4!=2){

		stepsWithoutEating=0;

		int r = rand()%(2)+1;

		return r;
	}

	//n3 and n4 are ants, n1 and n2 are not
	if(n1!=2&&n2!=2&&n3==2&&n4==2){

		stepsWithoutEating=0;


		int r = rand()%(2)+3;

		return r;
	}

	//n1 and n3 are ants, n2 and n4 are not
	if(n1!=2&&n2==2&&n3!=2&&n4==2){

		stepsWithoutEating=0;

		int r = rand()%(2);

		if(r==0){return 3;}

		return r;
	}

	//n2 and n4 are ants, n1 and n3 are not
	if(n1==2&&n2!=2&&n3==2&&n4!=2){

		stepsWithoutEating=0;

		int r = rand()%(2)+1;

		if(r==1){return 4;}

		return r;
	}

	//n1 and n4 are ants, n2 and n3 are not
	if(n1==2&&n2!=2&&n3!=2&&n4==2){

		stepsWithoutEating=0;

		int r = rand()%(2);

		if(r==0){return 4;}

		return r;
	}

	//n2 and n3 are ants, n1 and n4 are not
	if(n1!=2&&n2==2&&n3==2&&n4!=2){

		stepsWithoutEating=0;

		int r = rand()%(2)+2;

		return r;
	}

	//Cases with off grid/other doodlebugs

	//If top and right are empty and 3/4 are off grid
	if(n1==0&&n2==0&&n3==3&&n4==3){

		int r = rand()%(2)+1;

		return r;
	}

	//If bottom and right are empty and 1/4 are off grid
	if(n1==3&&n2==0&&n3==0&&n4==3){

		int r = rand()%(2)+2;

		return r;
	}

	//If left and bottom are empty and 1/2 are off grid
	if(n1==3&&n2==3&&n3==0&&n4==0){

		int r = rand()%(2)+3;

		return r;
	}

	//If left and top are empty and 2/3 are off grid
	if(n1==0&&n2==3&&n3==3&&n4==0){

		int r = rand()%(2);

		if(r==0){return 4;}

		return r;
	}

	//Cases if one space is a doodlebug or off, the rest are empty

	//If left side is off grid or a doodlebug
	if(n1==0&&n2==0&&n3==0&&n4!=0&&n4!=2){

		int r = rand()%(3)+1;

		return r;
	}

	//If the right side is off the grid or a doodlebug
	if(n1==0&&n2!=0&&n2!=2&&n3==0&&n4==0){

		int r = rand()%(3)+1;

		if(r==2){return 4;}

		return r;
	}

	//If the top side is off the grid or a doodlebug
	if(n1!=0&&n1!=2&&n2==0&&n3==0&&n4==0){

		int r = rand()%(3)+2;

		return r;
	}

	//If the bottom side is off the grid or a doodlebug
	if(n1==0&&n2==0&&n3!=0&&n3!=2&&n4==0){

		int r = rand()%(3)+1;

		if(r==3){return 4;}

		return r;
	}

	//Cases if two spots are doodlebugs or off grid

	//Top and right can't be moved to
	if(n1!=0&&n1!=2&&n2!=0&&n2!=2&&n3==0&&n4==0){

		int r = rand()%(2)+3;

		return r;
	}

	//Bottom and left can't be moved to
	if(n1==0&&n2==0&&n3!=0&&n3!=2&&n4!=0&&n4!=2){

		int r = rand()%(2)+1;

		return r;
	}

	//Top and bottom can't be moved to
	if(n1!=0&&n1!=2&&n3!=0&&n3!=2&&n2==0&&n4==0){

		int r = rand()%(2)+1;

		return r;
	}

	//Left and right can't be moved to
	if(n2!=0&&n2!=2&&n4!=0&&n4!=2&&n1==0&&n3==0){

		int r = rand()%(2)+1;

		if(r==2){return 3;}

		return r;
	}

	//Top and left can't be moved to
	if(n1!=0&&n1!=2&&n4!=0&&n4!=2&&n2==0&&n3==0){

		int r = rand()%(2)+1;

		return r;
	}

	//Bottom and right can't be moved to
	if(n2!=0&&n2!=2&&n3!=0&&n3!=2&&n1==0&&n4==0){

		int r = rand()%(2)+1;

		return r;
	}

	//If everything fails, stay put
	return 0;
}

int Doodlebug::whereToBreed(int n1,int n2,int n3,int n4){

	//Cases where one space is available to breed to
	if(n1==0&&n2!=0&&n3!=0&&n4!=0){return 1;}
	if(n1!=0&&n2==0&&n3!=0&&n4!=0){return 2;}
	if(n1!=0&&n2!=0&&n3==0&&n4!=0){return 3;}
	if(n1!=0&&n2!=0&&n3!=0&&n4==0){return 4;}

	//Cases where two spaces are available to breed to

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

	return 0;

}

/**
 * Destructor for DB
 * @return Does not return anything
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

