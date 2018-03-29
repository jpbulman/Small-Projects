/*
 * Board.h
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"

class Board {
public:
	//Constructor for a playable board. Takes in a length and the number of each org. to place
	Board(int sideLength,int numAnts,int numDoodleBugs);

	//Destructor
	virtual ~Board();

	//Prints the board
	void printBoard();

	//Move the Doodlebugs
	void moveDB();

	//Move the Ants
	void moveAnts();

	//Move the characters (the ants and the Doodlebugs)
	void moveChars();

	//Returns the type of character in the given coordinates
	//0 means empty, 1 means Doodlebug, 2 means Ant, 3 means off grid
	int getTypeInSpace(int j,int i);

	//Breed a Doodlebug that is at a given y (j) and x (i)
	void breedDoodlebug(int j,int i);

	//Breed an Ant that is at a given y (j) and x (i)
	void breedAnt(int j,int i);

	//Determines if there are any organisms left or not
	bool isEveryoneDead();

	//Gets the total number of Ants
	int getTotalAntNum();

	//Gets the total number of remaining Ants
	int getNumRemainingAnts();

	//Gets the total number of DBs
	int getTotalDBNum();

	//Gets the total number of remaining DBs
	int getNumRemainingDB();

private:
	//The length of the grid
	int sideLength;

	//A two dimensional array of pointers to Organisms
	Organism*** theBoard;

	//The total number of Ants over the simulation
	int totalNumberOfAnts;

	//The number of ants remaining at a step
	int numAntsRemaining;

	//The total number of Doodlebugs over the simulation
	int totalNumberOfDB;

	//The total number of DBs remaining
	int numDBRemaining;

};

#endif /* BOARD_H_ */
