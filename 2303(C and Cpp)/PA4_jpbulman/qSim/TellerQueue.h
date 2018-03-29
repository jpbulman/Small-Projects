/*
 * TellerQueue.h
 *
 *  Created on: Feb 14, 2018
 *      Author: jpbulman
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_

#include "Customer.h"

class TellerQueue {

	struct personInLine{
		Customer c;
		personInLine* prev;
		personInLine* ahead;
	};

public:
	//Default constructor
	TellerQueue();
	//Destructor
	virtual ~TellerQueue();
	//Adding a customer to the line
	void addToLine(Customer c);
	//Get the number of the line with the shortest length
	int shortestLineNum();
	//Update the shortest line
	void updateShortestLine(int i);
	//Gets the length of a line
	int getLength();
	//Gets the customer at the front of the line
	Customer getFrontCust();

private:
	//Head of the line
	personInLine* head;
	//Current person being looked at in line
	personInLine* currPerson;
	//Number to represent the line that is the shortest
	int shortestLine;

};

#endif /* TELLERQUEUE_H_ */
