/*
 * PA5.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: jpbulman
 */
#include <iostream>
#include <cstdlib>
#include "Board.h"
using namespace std;

int main(int argc,char* argv[]){

	//./PA5 gridsize numDB numAnts timesteps seed pause

	//Variables for params
	int gridSize, numDB, numAnts, timeSteps, seed, pause;

	//Switch the number of arguments to set them to the defaults or to the passed values
	switch(argc){

	case 7: gridSize=atoi(argv[1]);numDB=atoi(argv[2]);numAnts=atoi(argv[3]);
	timeSteps=atoi(argv[4]);seed=atoi(argv[5]);pause=atoi(argv[6]);break;

	case 6: gridSize=atoi(argv[1]);numDB=atoi(argv[2]);numAnts=atoi(argv[3]);
	timeSteps=atoi(argv[4]);seed=atoi(argv[5]);pause=0;break;

	case 5: gridSize=atoi(argv[1]);numDB=atoi(argv[2]);numAnts=atoi(argv[3]);
	timeSteps=atoi(argv[4]);seed=1;pause=0;break;

	case 4: gridSize=atoi(argv[1]);numDB=atoi(argv[2]);numAnts=atoi(argv[3]);
	timeSteps=1000;seed=1;pause=0;break;

	case 3: gridSize=atoi(argv[1]);numDB=atoi(argv[2]);numAnts=100;timeSteps=1000;seed=1;
	pause=0;break;

	case 2: gridSize=atoi(argv[1]);numDB=5;numAnts=100;timeSteps=1000;seed=1;
	pause=0;break;

	//All the default values for the params
	default: gridSize=20;numDB=5;numAnts=100;timeSteps=1000;seed=1;
	pause=0;break;

	}

	srand(seed);

	//Makes a new board with the given params
	Board b(gridSize,numAnts,numDB);

	//Prints the initial state of the board
	std::cout<<"Starting state:"<<std::endl;
	b.printBoard();
	std::cout<<""<<std::endl;

	//If the user does not want pausing
	if(pause==0){
		//i is a counter that keeps track of each timestep
		//Loop Invariant: Moves the organisms and prints the board each iteration
		for(int i=0;i<timeSteps;i++){
			//Move the characters (organisms)
			b.moveChars();

			//Print the board
			b.printBoard();

			//If all the organisms die, than return
			if(b.isEveryoneDead()){return 0;}

			//Put a line break to seperate the next print
			std::cout<<""<<std::endl;
		}
	}
	//If the user does want pausing
	else{

		//Counter for number of timesteps
		int i = 0;

		//Loop Invariant: Waits for the user to hit enter, and then moves/prints the board
		while(i<timeSteps){

		//Character to get the enter key
		char c;
		std::cout<<"Please hit enter";

		//std::cin works for formatted text, but need cin.get() for input like enter
		c=cin.get();

		//If something besides enter is inputed (not typed, but put in)
		if(c!='\n'){return 0;}

		//Increases the number of time steps completed
		i++;

		//Move the characters on the board
		b.moveChars();

		//Print the board
		b.printBoard();

		//If all the organisms die, than return
		if(b.isEveryoneDead()){return 0;}

		}

	}

	//Prints out the statistics of the simulation

	std::cout<<"Gridsize: "<<gridSize<<" Number of Doodlebugs: "<<numDB<<" Number of ants: "<<
			numAnts<<" Time steps: "<<timeSteps<<" Seed: "<<seed<<" Pause: "
			<<pause<<std::endl;

	std::cout<<"The number of steps taken was: "<<timeSteps<<std::endl;

	int totalAnts = b.getTotalAntNum();
	std::cout<<"The total number of Ants was: "<<totalAnts<<std::endl;

	int remainAnts = b.getNumRemainingAnts();
	std::cout<<"The total number of remaining Ants was: "<<remainAnts<<std::endl;

	int totalDB = b.getTotalDBNum();
	std::cout<<"The total number of Doodlebugs was: "<<totalDB<<std::endl;

	int remainDB = b.getNumRemainingDB();
	std::cout<<"The total number of remaining Doodlebugs was: "<<remainDB<<std::endl;

}



