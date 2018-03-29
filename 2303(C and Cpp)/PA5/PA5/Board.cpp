/*
 * Board.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */

#include "Board.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * Constructor for a Board
 * @param sideLength The length of the board
 * @param numAnts The number of Ants to be placed on the board
 * @param numDoodlebugs The number of Doodlebugs to be placed on the board
 * @return Does not return anything
 */
Board::Board(int sideLength, int numAnts, int numDoodlebugs) {

	//Starts the total number of Ants at 0
	totalNumberOfAnts=0;

	//The number of remaining Ants is currently how many are being made
	numAntsRemaining=numAnts;

	//Starts the total number of Doodlebugs at 0
	totalNumberOfDB=0;

	//The number of remaining DBs is currently how many are being made
	numDBRemaining=numDoodlebugs;

	//Sets the board length
	this->sideLength=sideLength;

	//Creates a two dimensional array of pointers to Organisms and allocates the proper memory
	Organism*** c = new Organism**[sideLength];

	//i is counter that keeps track of what column is being iterated on
	//Loop Invariant: Allocates proper memory for the column each iteration
	for(int i=0;i<sideLength;i++){

		//Gives the column memory so it is usable
		c[i] = new Organism*[sideLength];

		//j is counter to keep track of what column is being iterated
		//Loop Invariant: Sets each square in the grid initially to 0
		for(int j=0;j<sideLength;j++){

			//Sets the current square to 0
			c[i][j]=0;

		}

	}

	//k is an int that keeps track of the number of Ants being made
	//Loop Invariant: Makes an Ant each iteration and places it randomly within the board
	for(int k=0;k<numAnts;k++){

		//Generates random x and y coordinates [0,sideLength-1]
		int randx = rand()%(sideLength);
		int randy = rand()%(sideLength);

		//If the space is empty, fill it
		if(c[randy][randx]==0){

			//Make a new Ant
			Ant* a = new Ant(randx,randy);
			//Put the Ant in the empty spot
			c[randy][randx]=a;

		}
		//If the spot is filled
		else{

			//Loop Invariant: Generates new x and y coordinates until an empty space is found
			while(c[randy][randx]!=0){
				randx = rand()%(sideLength);
				randy = rand()%(sideLength);
			}

			//Creates the new Ant
			Ant* a = new Ant(randx,randy);
			//Fills the space
			c[randy][randx]=a;

		}

		//Increases the total number of Ants
		totalNumberOfAnts++;

	}

	//k is ant that keeps track of the number of Doodlebugs
	//Loop Invariant: Makes a new Doodlebug each time until the number of dbs has been reached
	for(int k=0;k<numDoodlebugs;k++){
		//Generates random x and y coordinates [0,sideLength-1]
		int randx = rand()%(sideLength-1);
		int randy = rand()%(sideLength-1);

		//If the space is empty, fill it
		if(c[randy][randx]==0){

			//Makes a new Doodlebug
			Doodlebug* d = new Doodlebug(randx,randy);
			//Fills the space
			c[randy][randx]=d;

		}
		//If the space is already filled
		else{

			//Loop Invariant: Generates new x and y coordinates until an empty space is found
			while(c[randy][randx]!=0){
				randx = rand()%(sideLength);
				randy = rand()%(sideLength);
			}

			//Makes a new Doodlebug
			Doodlebug* d = new Doodlebug(randx,randy);
			//Fills the space with the new db
			c[randy][randx]=d;

		}

		//Increases the total number of Doodlebugs
		totalNumberOfDB++;

	}

	//Sets the board field to be the generated board
	theBoard=c;

}

/**
 * Prints the board
 * @return void Does not return anything
 */
void Board::printBoard(){

	//i an int that is used a counter to keep track of what column is being viewed
	//Loop Invariant: Puts a line break at the end of every row to sepearate them
	for(int i=0;i<this->sideLength;i++){

		//j an int that is used a counter to keep track of what row is being viewed
		//Loop Invariant: Prints out the organism at the given location
		for(int j=0;j<this->sideLength;j++){

			//If the spot is empty
			if(this->theBoard[j][i]==0){std::cout<<"-";}
			//If the space is an Ant
			else if(this->theBoard[j][i]->isItPrey()){
				std::cout<<"o";
			}
			//If the space is a Doodlebug
			else if(!this->theBoard[j][i]->isItPrey()){
				std::cout<<"x";
			}
			//Otherwise, print a dash (like for 0)
			else {std::cout<<"-";}

		}

		//Seperates the rows with a line break
		std::cout<<""<<std::endl;

	}

}

/**
 * What is in space [j][i], 0 means empty, 1 means Doodlebug, 2 means Ant, 3 means off grid
 * @param j An int representing the y coordinate
 * @param i An int representing the x coordinate
 * @return Returns an in representing what type of object is in the space
 */
int Board::getTypeInSpace(int j,int i){

	//If the given coordinates are outside of the grid
	if(i>=sideLength||j>=sideLength||j<0||i<0){return 3;}
	//If the space is empty
	if(theBoard[j][i]==0){return 0;}
	//If the space is an Ant
	if(theBoard[j][i]->isItPrey()){return 2;}
	//Otherwise it must be a Doodlebug
	else{return 1;}

}

/**
 * Breeds the Doodlebug that is located at pos (i,j)
 * @param j An int representing the y coordinate
 * @param i An int representing the x coordinate
 * @return void Does not return anything
 */
void Board::breedDoodlebug(int j,int i){

	//New DB means the total +=1;
	totalNumberOfDB++;

	//An int saying what type the db's above neighbor is
	int above = this->getTypeInSpace(j,i-1);
	//What type its left neighbor is
	int right = this->getTypeInSpace(j+1,i);
	//Neighbor below
	int below = this->getTypeInSpace(j,i+1);
	//Neighbor to the left
	int left = this->getTypeInSpace(j-1,i);

	//An int saying where the db should breed
	//1-up 2-right 3-down 4-left
	int toBreed = theBoard[j][i]->whereToBreed(above,right,below,left);

	//Resets the number of steps to breed back to 0
	theBoard[j][i]->resetSteps();
	//Switches the dbs eligibility to breed
	theBoard[j][i]->switchElgBreed();

	//If the space where the child should go is above
	if(toBreed==1){

		//Make a Doodlebug (saying it already has moved)
		Doodlebug* d = new Doodlebug(j,i-1,true);
		//Make the spot above the new Doodlebug
		theBoard[j][i-1]=d;

	}
	//If the space where the child should go is to the right
	if(toBreed==2){

		//Make a Doodlebug
		Doodlebug* d = new Doodlebug(j+1,i,true);
		//Make the right spot the new Doodlebug
		theBoard[j+1][i]=d;

	}
	//If the db should breed down
	if(toBreed==3){

		//Make a Doodlebug
		Doodlebug* d = new Doodlebug(j,i+1,true);
		//Make the spot below the new Doodlebug
		theBoard[j][i+1]=d;

	}
	//If the db should breed left
	if(toBreed==4){

		//Make a Doodlebug
		Doodlebug* d = new Doodlebug(j-1,i,true);
		//Makes the spot to the left the new Doodlebug
		theBoard[j-1][i]=d;

	}
	//If there is nowhere to breed, the eligibility to breed will stay true until it has the
	//option to do so

}

/**
 * Has the Ant at (i,j) breed
 * @param j An int representing the y coordinate
 * @param i An int representing the x coordinate
 * @return void Does not return anything
 */
void Board::breedAnt(int j,int i){

	//One more being born, so total +=1
	totalNumberOfAnts++;

	//What is in the space above the Ant
	int above = this->getTypeInSpace(j,i-1);
	//To the right
	int right = this->getTypeInSpace(j+1,i);
	//Below the Ant
	int below = this->getTypeInSpace(j,i+1);
	//To the left
	int left = this->getTypeInSpace(j-1,i);

	//What direction the Ant should breed
	//1-up 2-right 3-down 4-left 0-Wait
	int toBreed = theBoard[j][i]->whereToBreed(above,right,below,left);

	//Resets the number of steps to breed
	theBoard[j][i]->resetSteps();
	//Switches the Ant's eligibility to breed
	theBoard[j][i]->switchElgBreed();

	//If the Ant should breed up
	if(toBreed==1){

		//Make a new Ant
		Ant* a = new Ant(j,i-1,true);
		//Make the space one up the new Ant
		theBoard[j][i-1]=a;

	}
	//If breeding should occur to the right
	if(toBreed==2){

		//Makes the Ant
		Ant* a = new Ant(j+1,i,true);
		//Sets right space to the new Ant
		theBoard[j+1][i]=a;

	}
	//Breeding down
	if(toBreed==3){

		//Makes a new Ant
		Ant* a = new Ant(j,i+1,true);
		//Make the space downwards the new Ant
		theBoard[j][i+1]=a;

	}
	//If the Ant should breed left
	if(toBreed==4){

		//Makes a new Ant
		Ant* a = new Ant(j-1,i,true);
		//Sets the left space to the new Ant
		theBoard[j-1][i]=a;

	}

}

/**
 * Moves the Doodlebugs on the board
 * @return void Does not return anything
 */
void Board::moveDB(){

	//i an int that is used a counter to keep track of what column is being viewed
	//Loop Invariant: Goes through all the spaces in the grid
	for(int i=0;i<sideLength;i++){

		//j an int that is used a counter to keep track of what row is being viewed
		//Loop Invariant: Checks if the space is a db, and moves it if so
		for(int j=0;j<sideLength;j++){

			//If the space is not empty
			if(theBoard[j][i]!=0){

				//If the space is a db and it has not already moved
			if(!theBoard[j][i]->isItPrey()&&!theBoard[j][i]->hasItMoved()){

				//Same principle as in methods above
				//Neighbor upwards
				int above = this->getTypeInSpace(j,i-1);
				//Right neighbor
				int right = this->getTypeInSpace(j+1,i);
				//Neighbor below
				int below = this->getTypeInSpace(j,i+1);
				//Neighbor to the left
				int left = this->getTypeInSpace(j-1,i);

				//Space that the db should move to
				//1-up 2-right 3-down 4-left 0-stay
				int moveTo = theBoard[j][i]->move(above,right,below,left);

				//If the db should move up
				if(moveTo==1){
					//Set the up space to the current db
					theBoard[j][i-1]=theBoard[j][i];
					//Make the old space empty
					theBoard[j][i]=0;

					//If the db has starved, die
					if(theBoard[j][i-1]->isItStarved()){
						theBoard[j][i-1]=0;
					}
					//If it is now eligible to breed, it should do so
					else if(theBoard[j][i-1]->canBreed()){
						this->breedDoodlebug(j,i-1);
					}

				}
				//If the db should move right
				if(moveTo==2){
					//Set the new space equal to the Doodlebug
					theBoard[j+1][i]=theBoard[j][i];
					//Make old space 0
					theBoard[j][i]=0;

					//If the db has starved, die
					if(theBoard[j+1][i]->isItStarved()){
						theBoard[j+1][i]=0;
					}
					//If it can breed, do so
					else if(theBoard[j+1][i]->canBreed()){
						this->breedDoodlebug(j+1,i);
					}

				}
				//If the db should move down
				if(moveTo==3){
					//Make the new space filled with the db
					theBoard[j][i+1]=theBoard[j][i];
					//Clear the old space
					theBoard[j][i]=0;

					//If the db has starved, make it die
					if(theBoard[j][i+1]->isItStarved()){
						theBoard[j][i+1]=0;
					}
					//If it can breed, then do so
					else if(theBoard[j][i+1]->canBreed()){
						this->breedDoodlebug(j,i+1);
					}

				}
				//If the Doodlebug should move left
				if(moveTo==4){
					//Set the new (left) space to the db
					theBoard[j-1][i]=theBoard[j][i];
					//Clear the old space
					theBoard[j][i]=0;

					//If the organism has starved, die
					if(theBoard[j-1][i]->isItStarved()){
						theBoard[j-1][i]=0;
					}
					//Breed if possible
					else if(theBoard[j-1][i]->canBreed()){
						this->breedDoodlebug(j-1,i);
					}

				}

			}

			}

		}

	}

	//Resets all the dbs 'hasMoved' booleans to no (false)

	//Resets before entering the loop
	numDBRemaining=0;

	//i is an int counter to keep track of columns
	//Loop Invariant: Cycles through all of the possible spaces on the grid
	for(int i=0;i<sideLength;i++){
		//j is an int counter to keep track of rows
		//Loop Invariant: Checks for an db, if one is there, reset it and count it
		for(int j=0;j<sideLength;j++){
			//If the space is not empty
			if(theBoard[j][i]!=0){
				//If the space is filled with a Doodlebug
				if(!theBoard[j][i]->isItPrey()){
					//Increases the total number of DB
					numDBRemaining++;
					//Set hasMoved to false so that next turn it can moveS
					theBoard[j][i]->setHasMoved(false);
				}
			}
		}
	}

}
/**
 * Moves all the Ants on the board
 * @return void Does not return anything
 */
void Board::moveAnts(){

	//i an int that is used a counter to keep track of what column is being viewed
	//Loop Invariant: Goes through all the spaces in the grid
	for(int i=0;i<sideLength;i++){

		//i an int that is used a counter to keep track of what row is being viewed
		//Loop Invariant: Checks each space to see if it is an Ant, and moves it if so
		for(int j=0;j<sideLength;j++){

			//If the space is not empty
			if(theBoard[j][i]!=0){

				//If the space is an Ant and has not moved
			if(theBoard[j][i]->isItPrey()&&!theBoard[j][i]->hasItMoved()){

				//Same idea as techniques in methods above
				//Neighbor adjacent on top
				int above = this->getTypeInSpace(j,i-1);
				//To the right
				int right = this->getTypeInSpace(j+1,i);
				//Neighbor below
				int below = this->getTypeInSpace(j,i+1);
				//Neighbor to the left
				int left = this->getTypeInSpace(j-1,i);

				//What direction the Ant should move in
				//1-up 2-right 3-down 4-left 0-stay
				int moveTo = theBoard[j][i]->move(above,right,below,left);

				//If moving up
				if(moveTo==1){
					//Set the space above to the Ant
					theBoard[j][i-1]=theBoard[j][i];
					//Clear old space
					theBoard[j][i]=0;

					//Breed if possible
					if(theBoard[j][i-1]->canBreed()){
						this->breedAnt(j,i-1);
					}

				}
				//If the Ant is moving right
				if(moveTo==2){
					//Set the space to the right to the Ant
					theBoard[j+1][i]=theBoard[j][i];
					//Clear old space
					theBoard[j][i]=0;

					//Breed if possible
					if(theBoard[j+1][i]->canBreed()){
						this->breedAnt(j+1,i);
					}

				}
				//If the Ant is moving down
				if(moveTo==3){
					//Make the space below the Ant
					theBoard[j][i+1]=theBoard[j][i];
					//Clear the old space
					theBoard[j][i]=0;

					//Breed if possible
					if(theBoard[j][i+1]->canBreed()){
						this->breedAnt(j,i+1);
					}

				}
				//If the Ant is moving left
				if(moveTo==4){
					//Set the left space to the Ant
					theBoard[j-1][i]=theBoard[j][i];
					//Clear its old space
					theBoard[j][i]=0;

					//Breed if possible
					if(theBoard[j-1][i]->canBreed()){
						this->breedAnt(j-1,i);
					}

				}

			}

			}

		}

	}

	//Resets all the Ants' 'hasMoved' booleans to no (false)


	//Resets the number remaining before going into the loop to count them
	numAntsRemaining=0;

	//i is an int counter to keep track of columns
	//Loop Invariant: Cycles through all of the possible spaces on the grid
	for(int i=0;i<sideLength;i++){
		//j is an int counter to keep track of rows
		//Loop Invariant: Checks for an Ant, if one is there, reset it and count it
		for(int j=0;j<sideLength;j++){
			//If the space is not empty
			if(theBoard[j][i]!=0){
				//If the space is filled with an Ant
				if(theBoard[j][i]->isItPrey()){
					//Increases the number of remaining Ants
					numAntsRemaining++;
					//Reset hasMoved
					theBoard[j][i]->setHasMoved(false);
				}
			}
		}
	}

}

/**
 * Moves all of the characters (Organisms) on the board
 * @return void Does not return anything
 */
void Board::moveChars(){
	//Moves Doodlebugs first
	this->moveDB();
	//Moves Ants next
	this->moveAnts();
}

/**
 * Determines if no organisms are left
 * @return True if there are no organisms, false if there are some alive
 */
bool Board::isEveryoneDead(){

	//i is a counter for columns
	//Loop Invariant: Goes through all the possible spaces in the grid
	for(int i=0;i<sideLength;i++){

		//j is a counter for rows
		//Loop Invariant: Checks to see if the space is not empty
		for(int j=0;j<sideLength;j++){

			//If the space is not empty (aka occupied), there is an organism, so return false
			if(theBoard[j][i]!=0){return false;}

		}
	}

	//If all space have been tested and none caused the function to return, there must be
	//no organisms left, so return true
	return true;

}

/**
 * Gives the total number of Ants over the simulation
 * @return totalNumberOfAnts Returns the total number of Ants
 */
int Board::getTotalAntNum(){
	return totalNumberOfAnts;
}

/**
 * Gives the number of remaining Ants
 * @return numAntsRemaining Returns the number of Ants left on the board
 */
int Board::getNumRemainingAnts(){
	return numAntsRemaining;
}

/**
 * Gets the total DB num
 * @return totalNumberOfDB Returns the total number of Doodlebugs over the simulation
 */
int Board::getTotalDBNum(){
	return totalNumberOfDB;
}

/**
 * Returns the number of remaining DBs
 * @return numDBRemaining Returns the number of DBs left on the board
 */
int Board::getNumRemainingDB(){
	return numDBRemaining;
}

/**
 * Destructor
 * @return void Does not return anything
 */
Board::~Board() {
	// TODO Auto-generated destructor stub
}

