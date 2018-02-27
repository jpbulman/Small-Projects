/*
 * Ant.h
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

//Extends Organism
class Ant : public Organism{
public:
	//Constructor with x and y
	Ant(int x,int y);

	//Overloaded constructor with x and y coordinates and with a boolean saying if it has moved
	Ant(int x,int y,bool hasMoved);

	//Destructor
	virtual ~Ant();

	//Method that returns an int representing where it should move
	//1-up 2-right 3-down 4-left 0-stay
	//Overrides parent method
	int move(int o,int t,int th,int f);

	//Method that returns an int representing where it should breed
	//1-up 2-right 3-down 4-left 0-wait
	//Overrides parent method
	int whereToBreed(int n1,int n2,int n3,int n4);

	//Tells the call if the Ant is starved or not (it never can starve)
	//Overrides parent method
	bool isItStarved();

};

#endif /* ANT_H_ */
