/*
 * Organism.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */

#include "Organism.h"

/**
 * Constructor for Organism
 * @param isPrey If the organism is an ant or not
 * @param x The x coordinate of the organism
 * @param y The y coordinate of the organism
 * @return Does not return anything
 */
Organism::Organism(bool isPrey,int x,int y) {
	//Sets isPrey to the passed param
	this->isPrey=isPrey;
	//Sets x
	xVal=x;
	//Sets y
	yVal=y;
	//Has not moved yet, so starts with false
	hasMoved=false;
	//Has not taken any steps yet, so starts at 0
	stepsTaken=0;
	//Not eligible to breed by default
	eligbleToBreed=false;
}

/**
 * Overloaded constructor for Organism
 * @param isPrey If the organism is an ant or not
 * @param x The x coordinate of the organism
 * @param y The y coordinate of the organism
 * @param hasMoved If the organism has moved or not already
 * @return Does not return anything
 */
Organism::Organism(bool isPrey,int x,int y,bool hasMoved) {
	//Sets isPrey to the passed parameter
	this->isPrey=isPrey;
	//Sets x
	xVal=x;
	//Sets y
	yVal=y;
	//Sets hasMoved to the passed parameter
	this->hasMoved=hasMoved;
	//Has not taken any steps yet, so starts at 0
	stepsTaken=0;
	//Not eligible to breed by default
	eligbleToBreed=false;
}

/**
 * Increments the number of steps the organism has taken by 1
 * @return void Does not return anything
 */
void Organism::incrStep(){
	//Increments number of steps taken
	stepsTaken++;
}

/*
 * Resets the number of steps the organism has taken to 0
 * @return void Does not return anything
 */
void Organism::resetSteps(){
	//Sets the number of steps taken to 0
	stepsTaken=0;
}

/**
 * Sets the boolean hasMoved (Doing this without a setter was hard)
 * @param x The boolean for hasMoved
 * @return void Does not return anything
 */
void Organism::setHasMoved(bool x){
	//Sets hasMoved
	this->hasMoved=x;
}

/**
 * Returns the number of steps taken by the organism
 * @return stepsTake Returns an in representing the number of steps the organism has taken
 */
int Organism::getSteps(){
	//Returns the number of steps
	return stepsTaken;
}

/**
 * Switches the value of eligibleToBreed
 * @void Does not return anything
 */
void Organism::switchElgBreed(){
	//Sets the field to the opposite value
	eligbleToBreed=!eligbleToBreed;
}

/**
 * Determines if the organism is prey (an ant) or not
 * @return isPrey Returns whether or not the organism is prey
 */
bool Organism::isItPrey(){
	//Returns the boolean representing if it is an ant or not
	return isPrey;
}

/**
 * Determines if the organism is eligible to breed or not
 * @return eligibleToBreed Returns if the organism can breed or not
 */
bool Organism::canBreed(){
	//Returns the boolean representing if the organism can breed or not
	return eligbleToBreed;
}

/**
 * Returns if the organism has moved already
 * @return hasMoved Gives back a boolean representing if the organism has already moved
 */
bool Organism::hasItMoved(){
	//Returns if the organism has moved or not
	return hasMoved;
}

/**
 * Destructor
 * @return does not return anything
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

