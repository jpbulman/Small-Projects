/*
 * qSim.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: jpbulman
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "eventLinkedList.h"
#include "CustomerEvent.h"
#include "Customer.h"
#include "Teller.h"
#include "TellerQueue.h"

/**
 * The main function
 * @param argc The number of arguments being passed into the terminal
 * @param argv[] The array of actual arguments in order
 * @return int Returns an int signaling how the compilation went
 */
int main(int argc, char* argv[]) {

	//Variables for the arguments being passed in
	int numCustomers, numTellers, simTime, avgServiceTime, userSeed;
	switch (argc) {
	//If the users passes in a seed
	case 6:
		//Set the user seed
		userSeed = atoi(argv[5]);
		//Set the other parameters
		numCustomers = atoi(argv[1]);
		numTellers = atoi(argv[2]);
		simTime = atoi(argv[3]);
		avgServiceTime = atoi(argv[4]);
		//Invoke the user seed
		srand(userSeed);
		break;
	case 5:
		//Sets the parameters if there is no user seed given
		numCustomers = atoi(argv[1]);
		numTellers = atoi(argv[2]);
		simTime = atoi(argv[3]);
		avgServiceTime = atoi(argv[4]);
		break;
	default:
		//Anything else
		std::cout << "Only 4 or 5 arguments allowed." << std::endl;
		break;
	}

	//Prints the parameters that were received
	std::cout << "Number of customers: " << numCustomers << std::endl;
	std::cout << "Number of tellers: " << numTellers << std::endl;
	std::cout << "Simulation time: " << simTime<< std::endl;
	std::cout << "Average service time: " << avgServiceTime << std::endl;
	//If there was a seed endtered
	if(argc>5){	std::cout << "Seed: " << userSeed << std::endl;}

	//Extra line for spacing
	std::cout<<""<<std::endl;



	//-----Simulation with multiple lines-----

	//Starting simulation with tellers having their own lines
	std::cout<<"Starting simulation with one line for each teller"<<std::endl;

	//The clock during the simulation
	float simClock = 0;

	//The main event queue (tried to name it event queue after I realized it could be one class, but Eclipse would not let me
	//refactor the class name
	eventLinkedList mainEventQ;

	//Initializes customers and their respective arrival events
	//J is a counter will make the loop go as many times as there are customers
	//Loop Invariant: Makes a new random customer each iteration, makes an arrival event, and puts the arrival in the event q
	for(int i=0;i<numCustomers;i++){
		//New customer
		Customer* c = new Customer(simTime);
		//Makes an arrival event
		CustomerEvent* ce = new CustomerEvent(*c,c->getTime());
		//Adds the arrival to the event q
		mainEventQ.addToList(*ce);
	}

	//Array of tellers
	Teller tellerList[numTellers];
	//Parallel array of teller lines (meaning listOfLines[0] will be the line for tellerList[0])
	TellerQueue listOfLines[numTellers];
	//Temporary line holder for finding the shortest length line
	TellerQueue e;

	//Initializes tellers and their lines and puts them into the arrays
	//J is a counter that will have the loop make as many lines as there are tellers
	//Loop Invariant: Makes a teller and a line each iteration and stores them into the teller arrays
	for(int j=0;j<numTellers;j++){
		//Makes a new teller
		Teller* t = new Teller(avgServiceTime,0);
		//Stores it into the array
		tellerList[j]=*t;
		//Makes a line for the teller
		TellerQueue* q = new TellerQueue();
		//Stores in the array
		listOfLines[j]=*q;
	}

	//A counter to keep track of the number of customers
	int customerCount = 0;

	//Goes through the event queue until there are no more events to process (when it reaches 0)
	//Loop Invariant: The event queue will process each event and then at the end, remove the event, advance the clock, and
	//go on to the next event
	while(mainEventQ.getFirstTime()!=0){

		//Advances clock to next event
		simClock=mainEventQ.getHeadVal();

//		for(int i=0;i<numTellers-1;i++){
//			Teller t = tellerList[i];
//			TellerQueue q;
//
//			int smallestLine=0;
//			int smallestLength;
//
//			for(int j=0;j<numTellers-1;j++){
//				q=listOfLines[j];
//				if(j==0){smallestLength=q.getLength();}
//				if(q.getLength()<smallestLength){smallestLine=j;smallestLength=q.getLength();}
//			}
//
//			if(t.isTellerAvail()){}
//		}

		std::cout<<"Customer "<<customerCount<<" has arrival time: "<<mainEventQ.getFirstTime()<<std::endl;
		mainEventQ.removeHeadFromList();
		customerCount++;
	}

	//Prints the time the last event finished at
	std::cout<<"Ending time was: "<<simClock<<std::endl;

	//Count to hold average idle time
	float idleTime = 0;

	//Loop Invariant: Goes through the teller array and adds their idle time to the running count
	for(int i=0;i<numTellers;i++){
		Teller t = tellerList[i];
		idleTime+=t.getIdlTime();
	}

	//Makes the idleTime the average idle time
	idleTime/=numTellers;

	//Prints stats about actual versus hypothetical service time
	std::cout<<"The average idle time was "<<" seconds"<<idleTime<<std::endl;

	//Number to keep a collection of all the tellers' serve times
	float serviceTime = 0;

	//Loop Invariant: Goes through the teller array and adds their service time to the running count
	for(int i=0;i<numTellers;i++){
		Teller t = tellerList[i];
		serviceTime+=t.getServT();
	}

	//Makes the serviceTime the average service time
	serviceTime/=numTellers;

	//Prints stats about actual versus hypothetical service time
	std::cout<<"The real average service time was "<<serviceTime<<" versus the given average which was "
			<<avgServiceTime<<std::endl;
	std::cout<<"This made for a "<<(avgServiceTime/serviceTime)*100<<"% difference"<<std::endl;

	std::cout<<"\n"<<"Entering next simulation"<<std::endl;




	//-----Simulation with one line-----

	//Reset the clock for the next simulation
	simClock = 0;

	//Main event q for second simulation
	eventLinkedList mainEventQ1;

	//Initializes customers and their respective arrival events
	//J is a counter will make the loop go as many times as there are customers
	//Loop Invariant: Makes a new random customer each iteration, makes an arrival event, and puts the arrival in the event q
	for(int i=0;i<numCustomers;i++){
		//New customer
		Customer* c = new Customer(simTime);
		//Makes an arrival event
		CustomerEvent* ce = new CustomerEvent(*c,c->getTime());
		//Adds the arrival to the event q
		mainEventQ1.addToList(*ce);
	}

	//Array of tellers
	Teller tellerList1[numTellers];

	//Initializes tellers and puts them into an array
	//J is a counter that will have the loop make as many tellers as specified
	//Loop Invariant: Makes a teller each iteration and stores it into the teller array
	for(int j=0;j<numTellers;j++){
		//Makes a new teller
		Teller* t = new Teller(avgServiceTime,0);
		//Stores it into the array
		tellerList1[j]=*t;
	}

	TellerQueue mainLine;
	customerCount=0;

	//Goes through the event queue until there are no more events to process (when it reaches 0)
	//Loop Invariant: The event queue will process each event and then at the end, remove the event, advance the clock, and
	//go on to the next event
	while(mainEventQ1.getFirstTime()!=0){

		//Advances clock to next event
		simClock=mainEventQ1.getHeadVal();

		//Gets the event on the head
		Event e = mainEventQ1.headEvent();

		//Gets the customer from the event if the event is a customer event
		Customer c;
		if(e.getCust().getTime()!=0){c = e.getCust();}
		//Adds the customer to the line
		mainLine.addToLine(c);

		//Gets the next customer
		Customer curr = mainLine.getFrontCust();

		//J is a counter to keep track of tellers
		//Loop Invariant: Goes through the teller until it finds one that is available
		for(int j=0;j<numTellers;j++){
			//Makes a new teller
			Teller t = tellerList1[j];
			//If they are available, make the unavailable
			if(t.isTellerAvail()){t.startServ();}
		}

		std::cout<<"Customer "<<customerCount<<" has arrival time: "<<mainEventQ1.getFirstTime()<<std::endl;
		mainEventQ1.removeHeadFromList();
		customerCount++;
	}

	//Reset
	idleTime = 0;

	//Loop Invariant: Goes through the teller array and adds their idle time to the running count
	for(int i=0;i<numTellers;i++){
		Teller t = tellerList1[i];
		idleTime+=t.getIdlTime();
	}

	//Makes the idleTime the average idle time
	idleTime/=numTellers;

	//Prints stats about actual versus hypothetical service time
	std::cout<<"The average idle time was "<<idleTime<<" seconds"<<std::endl;

	//Reset
	serviceTime = 0;

	//Loop Invariant: Goes through the teller array and adds their service time to the running count
	for(int i=0;i<numTellers;i++){
		Teller t = tellerList1[i];
		serviceTime+=t.getServT();
	}

	//Makes the serviceTime the average service time
	serviceTime/=numTellers;

	//Prints stats about actual versus hypothetical service time
	std::cout<<"The real average service time was "<<serviceTime<<" versus the given average which was "
			<<avgServiceTime<<std::endl;
	//Calculates percent difference
	std::cout<<"This made for a "<<(avgServiceTime/serviceTime)*100<<"% difference"<<std::endl;

	return 0;
}

