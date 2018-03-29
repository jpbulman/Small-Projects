/*
 * Doodlebug.h
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Doodlebug : public Organism {
public:
	//Constructor that takes in an x and y coordinate
	Doodlebug(int x,int y);

	//Constructor that takes in an x and y coordinate, and a bool for if the db has moved or not
	Doodlebug(int x,int y,bool hasMoved);

	//Destructor
	virtual ~Doodlebug();

	//A function that determines what direction the db should move
	//1-up 2-right 3-bottom 4-left 0-Don't move
	//Overrides parent class method
	int move(int neighbor1Type,int n2,int n3,int n4);

	//Function that returns an int representing where the Doodlebug should breed
	//1-up 2-right 3-bottom 4-left 0-wait until later
	////Overrides parent class method
	int whereToBreed(int n1,int n2,int n3,int n4);

	//Determines if the db is starved or not
	//Overrides parent class method
	bool isItStarved();

private:
	//Boolean representing if the organism has starved yet
	bool isStarved;

	//The number of steps the db has taken without eating an ant
	int stepsWithoutEating;

};

#endif /* DOODLEBUG_H_ */
