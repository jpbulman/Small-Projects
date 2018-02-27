/*
 * Organism.h
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism {
public:
	//Constructor with a boolean for if its an ant, and x and y coords
	Organism(bool isPrey,int x,int y);

	//Overloaded constructor that is the same, but with an extra boolean that sets hasMoved
	Organism(bool isPrey,int x,int y,bool hasMovedYet);

	//Destructor
	virtual ~Organism();

	//Move function that returns an int representing where to go
	//1-up 2-right 3-bottom 4-left 0-stay
	virtual int move(int one,int two,int three,int four) = 0;

	//Function that returns an int representing where the organism should breed
	//1-up 2-right 3-bottom 4-left 0-wait until later
	virtual int whereToBreed(int n1,int n2,int n3,int n4) = 0;

	//Returns if the organism is starved or not (returns 0 if it is an ant)
	virtual bool isItStarved() = 0;

	//Returns if the organism can breed or not
	bool canBreed();

	//Determines if the organism is an ant or not (doodlebug)
	bool isItPrey();

	//Sets the has moved boolean (I found trying to do this without a setter was hard)
	void setHasMoved(bool x);

	//Returns if the organism has already moved or not
	bool hasItMoved();

	//Increments the number of steps the organism has taken
	void incrStep();

	//Gets the number of steps the organism has
	int getSteps();

	//Resets the number of steps to 0
	void resetSteps();

	//Switches the value of eligible to breed
	void switchElgBreed();


private:
	//Is the organism an ant or not
	bool isPrey;

	//x coord
	int xVal;

	//y coord
	int yVal;

	//If the organism has moved or not
	bool hasMoved;

	//The number of steps the organism has taken
	int stepsTaken;

	//Is the organism eligible to breed
	bool eligbleToBreed;

};

#endif /* ORGANISM_H_ */
